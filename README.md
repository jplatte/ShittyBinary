# Binary

A library I created for binary data in C++, because C++ only supports normal numbers
natively. See for yourself!

```C++
#include "binary.cc"
#include "iostream"

using namespace std;
int main ()
{
   CBinary x=CBinary       ("0100010010");
   CBinary y=CBinary       ("1010001010");

   cout << x.Not()._<<endl// 1011101101
      << y.Not()._<<endl  // 0101110101
      << x.And(y)._       // 0000000010
      <<endl
      <<   y.Or(x)._      // 1110011010
      <<endl
      <<   x.XOr(y)._     // 1110011000
      <<endl;

   return 0.0;
}
```

For more usage information, just read the [source code][source]! It's self-documenting.

If you need any additional features, contact me at [git@github.com][email] or via Issues.

Also, it would be really cool if someone could port this to other languages, I'm sure
there are many other languages that don't support binary numbers!

[source]: https://github.com/jplatte/ShittyBinary/blob/master/c++/binary.cc#LC1
[email]: https://github.com/jplatte/ShittyBinary/issues
