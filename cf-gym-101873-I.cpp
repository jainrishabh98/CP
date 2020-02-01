#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    ll a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    ll dp[n+1];
    for(int i=1;i<=m;i++)
    {
        dp[i] = 0;
    }
    for(int i=m+1;i<=n;i++)
    {
        dp[i] = max(dp[i-1],dp[i-m]+a[i]);
    }
    cout<<dp[n];
}