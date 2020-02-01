#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int l=1;l<=t;l++)
    {
        ll n,k,ans = 10000000000000000;
        cin>>k>>n;
        pair<ll,ll> x[n];
        for(int i=0;i<n;i++)
        {
            cin>>x[i].first;
        }
        for(int i=0;i<n;i++)
        {
            cin>>x[i].second;
        }
        sort(x,x+n);
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j!=i)
                    pq.push(abs(x[j].first - x[i].first) + x[j].second);
            }
            int cnt = 0;
            ll temp  = 0;
            while(!pq.empty())
            {
                if(cnt<k)
                {
                    cnt++;
                    temp += pq.top();
                }
                pq.pop();
            }
            ans = min(ans,temp+x[i].second);
        }
        cout<<"Case #"<<l<<": "<<ans<<"\n";
    }
}