#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k,m,x;
        cin>>n>>k>>m;
        ll dp[k+1];
        for(int i=0;i<=k;i++)
            dp[i]=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            x %= m;
            if(x > k)
                continue;
            if(x==0) x +=m;
            while(x<=k)
                x +=m;
            x -= m;
            for(;x > 0;x-=m)
            {
                if(x==1)
                    dp[x] = (dp[x]+1)%mod;
                else
                    dp[x] = (dp[x] + dp[x-1])%mod;
            }
        }
        cout<<dp[k]<<"\n";
    }
}