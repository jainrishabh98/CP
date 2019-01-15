#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m = 1e9 + 7;
ll dp[200005];
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll a,b,h;
   cin>>a>>b;
   dp[0]=1;dp[1]=1;
   for(h=2;h*(h+1)/2<=(a+b);h++)
   {
       for(ll i = a;i>=h;i--)
       {
           (dp[i]+=dp[i-h])%=m;
       }
   }
   ll ans=0;
   h--;
   for(ll i=0;i<=a;i++)
   {
       if(((h*(h+1))/2)-i<=b)(ans+=dp[i])%=m;
   }
   cout<<ans<<"\n";
   return 0;
}