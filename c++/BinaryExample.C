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

   /* doesn't work for some reason
   cout << x.NAnd(y)._
      <<endl;*/

   return 0.0;
}
