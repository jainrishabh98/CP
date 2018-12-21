#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    { ll a,b;
      cin>>a>>b;
      ll g = __gcd(a,b);
      ll y = a/g;
      ll x = b/g;
      cout<<x<<" "<<y<<"\n";
    }
    return 0;
}