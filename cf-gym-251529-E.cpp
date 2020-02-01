#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll m[n],r[n];
    ll cnt = 0;
    for(int i=0;i<n;i++)
    {
        cin>>m[i]>>r[i];
        if(m[i]>r[i])
            cnt++;
    }
    if(cnt > n/2)
    {
        cout<<0;
        return 0;
    }
    ll dp[n+1];
    dp[0] = 0;
    dp[1] = 0;
    for(int i=2;i<=n;i++)
    {
        if(m[i-1] > r[i-1])
        {
            dp[i] = dp[i-1];
            if(m[i-2] <= r[i-2] && m[i-1]+m[i-2] > r[i-1]+r[i-2])
            {
                dp[i] = max(dp[i],dp[i-2] + 1);
            }
        }
        else
        {
            dp[i] = dp[i-1];
            if(m[i-2] > r[i-2] && m[i-1]+m[i-2] > r[i-1]+r[i-2])
            {
                dp[i] = max(dp[i],dp[i-2] + 1);
            }
            else if(m[i-2] <= r[i-2])
            {
                dp[i] = max(dp[i],dp[i-2]+1);
            }
        }
    }
    if(cnt <= (n-dp[n])/2)
    {
        cout<<-1;
        return 0;
    }
    int opt = 0;
    for(int i=1;i<=dp[n];i++)
    {
        if(cnt > (n-i)/2)
        {
            opt = i;
            break;
        }
    }
    // backtracking
    cout<<opt<<"\n";
    vector <pair<ll,ll>> v;
    int i = n;
    while(opt!=0 && i>=0)
    {
        if(dp[i]==dp[i-1])
            i--;
        else
        {
            v.push_back({i,i-1});
            i -= 2;
            opt--;
        }     
    }
    for(auto k:v)
    {
        cout<<k.first<<" "<<k.second<<"\n";
    }
}