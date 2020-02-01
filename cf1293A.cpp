#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,s,k;
        cin>>n>>s>>k;
        ll x;
        map<ll,int> mp;
        for(int i=0;i<k;i++)
        {
            cin>>x;
            mp[x] = 1;
        }
        ll ans = n;
        for(ll i=s;i<=min(s+1000,n);i++)
        {
            if(mp.find(i)==mp.end())
            {
                ans = i - s;
                break;
            }
        }
        for(ll i=s;i>=max((ll)1,s-1000);i--)
        {
            if(mp.find(i)==mp.end())
            {
                ans = min(ans,s - i);
                break;
            }
        }
        cout<<ans<<"\n";
    }
}