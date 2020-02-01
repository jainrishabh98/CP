#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        pair<ll,ll> p[n];
        ll dp[n];
        for(int i=0;i<n;i++)
            cin>>p[i].second>>p[i].first;
        sort(p,p+n);
        ll ans = 1e9;
        for(int i=0;i<n;i++)
        {
            ll low = 0,high = i,mid,pos=-1;
            while(low<=high)
            {
                mid = (low+high)/2;
                if(p[mid].first < p[i].second)
                {
                    pos = mid;
                    low = mid+1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            if(pos==-1)
                dp[i] = 0;
            else
            {
               ans = min(ans,dp[pos]);
               dp[i] = min(dp[pos]+i-pos,pos+1); 
            }
        }
        if(ans==1e9)
            cout<<-1<<"\n";
        else
            cout<<ans<<"\n";
    }
}