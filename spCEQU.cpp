#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    { ll a,b,c;
      cin>>a>>b>>c;
      ll g = __gcd(a,b);
      if(c%g==0)
        cout<<"Case "<<i<<": Yes\n";
      else
       cout<<"Case "<<i<<": No\n";
    }
return 0;
}