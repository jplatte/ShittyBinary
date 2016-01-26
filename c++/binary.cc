#ifdef BINARY
#error You are doing it wrong!
#else
#define BINARY

#include "string"


using namespace std;

class CBinary {
public:
   string _;
   explicit CBinary(string data){_=data;}
   CBinary():_(){}

   int Ln(void){
      int ln=_.size();
      return ln;
   }

   char& operator[] (int i){
      return _.at(i);
   }

   CBinary And (CBinary x)
   {
      CBinary y=*this;
      int i=0;
      while(i<x.Ln())
      {
         char result;
         if(x[i]=='1'&&y[i]=='1') result='1';
         else result='0';
         x[i++]=result;
      }
      return x;
   }

   CBinary Or (CBinary x)
   {
      CBinary y=*this;
      int i=0;
      while(i<x.Ln())
      {
         char result;
         if(x[i]=='0'&&y[i]=='0') result='0';
         else result='1';
         x[i++]=result;
      }
      return x;
   }

   CBinary Not ()
   {
      int i=0;
      while(i<this->Ln())
      {
         char result;
         if(_[i]=='1') result='0';
         else result='1';
         _[i++]=result;
      }
      return CBinary(_);
   }

   /*CBinary Not2 ()
   {
      int i=0;
      while(i<this->Ln())
      {
         char result;
         if(_[i]=='0') result='1';
         else result='0';
         _[i]=result;
      }
      return CBinary(_);
   }*/

   CBinary XOr (CBinary x)
   {
      CBinary y=*this;
      int i=0;
      while(i<x.Ln())
      {
         char result;
         if(x[i]=='0'&&y[i]=='0') result='0';
         if(x[i]=='0'&&y[i]=='1') result='1';
         if(x[i]=='1'&&y[i]=='0') result='1';
         if(x[i]=='1'&&y[i]=='1') result='0';
         x[i++]=result;
      }
      return x;
   }

   CBinary NAnd (CBinary x)
   {
      CBinary y=*this;
      int i=0;
      while(i<x.Ln())
      {
         char result;
         if(x[i]=='1'&&y[i]=='1') result='0';
         else result='1';
         x[i++]=result;
      }
      return x;
   }
};

#endif
