#include <iostream>

#define ll long long

using namespace std;

struct gcd_result {
   ll s;
   ll t;
   ll r;
};

gcd_result ext_gcd(int a, int b) {
   gcd_result old{ 1, 0, a };
   gcd_result cur{ 0, 1, b };

   while (cur.r != 0) {
      ll q = old.r / cur.r;

      auto tmp = cur;
      cur.r = old.r - q * cur.r;
      cur.s = old.s - q * cur.s;
      cur.t = old.t - q * cur.t;
      old = tmp;
   }
   return old;
}
int main(){
   
   int t;
   cin >> t;
   while (t--){
      int a, b;
      cin >> a >> b;
      auto res = ext_gcd(a, b);
      if (res.r != 1) {
         cout << "IMPOSSIBLE\n";
         continue;
      }
      while (res.t < 0 || res.s >= 0) {
         res.t += a;
         res.s -= b;
      }
      if (res.t > 1e9) {
         cout << "IMPOSSIBLE\n";
         continue;
      }else{
         cout << res.t << '\n';      
      }
   } 
}