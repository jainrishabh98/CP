#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{   
    ll m = 1e9 + 7;
    ll t,k;
    cin>>t>>k;
    ll a[t],b[t];
    for(int i=0;i<t;i++)
        cin>>a[i]>>b[i];
    ll mx = 1e5 + 1;
    ll dp[mx];
    dp[0]= 0;
    for(int i=1;i<mx;i++)
    {   
        if(i<k) {dp[i]=1;continue;}
        if(i==k) {dp[i]=2;continue;}
        dp[i] = (dp[i-1] + dp[i-k])%m;
        
    }
    for(int i=2;i<mx;i++)
    {
        dp[i] = (dp[i] + dp[i-1])%m;
    }
    for(int i=0;i<t;i++)
    {   
        // cout<<dp[a[i]]<<" "<<dp[b[i]]<<"\n";
        cout<<(dp[b[i]] - dp[a[i]-1] + m)%m<<"\n";
    }
    return 0;
}