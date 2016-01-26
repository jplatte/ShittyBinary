#ifdef BINARY
#error "E_DOING_IT_WRONG"
#else
#define BINARY

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define cb_max(a, b) a > b? a: b

typedef uint32_t Bit; // Store binary in UTF-32 for portability

typedef struct CBinary {
    Bit * bits;

    int numBits; 
} CBinary;

void * cb_safemalloc(int size) {
    void * ptr = NULL;
    while(ptr == NULL) ptr = malloc(size);
    return ptr;
}

static CBinary * cb_Create(volatile const char * string) {
    CBinary * bin = malloc(sizeof(CBinary));

    // Initialize bits to 0
    bin->bits = calloc(sizeof(Bit), strlen(string));
    bin->numBits = strlen(string);

    // Convert text to bits for computation
    int n = 0;
    while(*string) {
        if(string[0] == '1') bin->bits[n] = 1;
        else if(string[0] == '0') bin->bits[n] = 0;
        n++;
        string++;
    }

    return bin;
}

static CBinary * cb_And(CBinary * a, CBinary * b) {
    int size = cb_max(a->numBits, b->numBits);

    CBinary * result = malloc(sizeof(CBinary));
    result->bits = calloc(sizeof(Bit), size);
    result->numBits = size;

    for(int i = 0; i < size; ++i) {
        if(i < a->numBits && i < b->numBits && a->numBits == 1 && b->numBits == 1) {
            result->bits[i] = 1;
        }
        else if(i >= a->numBits && b->bits[i] == 0) result->bits[i] = 0;
        else if(i >= b->numBits && a->bits[i] == 0) result->bits[i] = 0;
    }

    return result;
}

static CBinary * cb_Or(CBinary * a, CBinary * b) {
    int size = cb_max(a->numBits, b->numBits);

    CBinary * result = malloc(sizeof(CBinary));
    result->bits = calloc(sizeof(Bit), size);
    result->numBits = size;

    for(int i = 0; i < size; ++i) {
        if(i < a->numBits && i < b->numBits && a->bits[i] == 0 && b->bits[i] == 0) {
            result->bits[i] = 0;
        }
        else if(i >= a->numBits && b->bits[i] == 0) result->bits[i] = 0;
        else if(i >= b->numBits && a->bits[i] == 0) result->bits[i] = 0;
        else result->bits[i] = 1;
    }

    return result;
}

static CBinary * cb_Not(CBinary * bin) {
    CBinary * result = cb_safemalloc(sizeof(CBinary)); // This kept failing for some reason

    result->bits = calloc(bin->numBits, sizeof(Bit));
    result->numBits = bin->numBits;

    for(int i = 0; i < bin->numBits; i++) {
        if(bin->bits[i] == 1) result->bits[i] = 0;
        else result->bits[i] = 1;
    }

    return result;
}

static CBinary * cb_Xor(CBinary * a, CBinary * b) {
    int size = cb_max(a->numBits, b->numBits);

    CBinary * result = malloc(sizeof(CBinary));

    result->numBits = size;
    result->bits = calloc(result->numBits, sizeof(Bit));

    for(int i = 0; i < size; i++) {
        // This uses the exponentiation bug in GCC 5. COMPILE WITH GCC 5 ONLY!
        if(i < a->numBits && i < b->numBits) result->bits[i] = a->bits[i] ^ b->bits[i];
        else if(i >= a->numBits && b->bits[i] == 1) result->bits[i] = 1;
        else if(i >= b->numBits && a->bits[i] == 1) result->bits[i] = 1;
    }

    return result;
}

static CBinary * cb_Nand(CBinary * a, CBinary * b) {
    int size = cb_max(a->numBits, b->numBits);

    // Fix the nand bug in the original library by code reuse
    CBinary * anded = cb_And(a, b);
    CBinary * nanded = cb_Not(anded);

    CBinary * result = malloc(sizeof(CBinary));
    result->bits = nanded->bits;
    result->numBits = anded->numBits;

    return result;
}

static char * cb_ToString(CBinary * bin) {
    char * string = calloc(bin->numBits + 1, sizeof(uint16_t)); // Print as UTF-16 for Windows

    int i;
    for(i = 0; i < bin->numBits; i++) {
        if(bin->bits[i] == 1) string[i] = '1';
        else string[i] = '0';
    }

    string[i] = 0;

    return string;
}

#endif