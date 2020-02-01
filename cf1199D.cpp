#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,q;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector <pair<ll,ll>> temp;
    cin>>q;
    int l,p,x;
    while(q--)
    {
        cin>>l;
        if(l==1)
        {
            cin>>p>>x;
            p--;
            temp.push_back({p,x});
        }
        else
        {
            cin>>x;
            temp.push_back({-1,x});
        }
    }
    ll ans[n];
    ll last_update = 0;
    for(int i=0;i<n;i++)
    {
        ans[i] = -1;
    }
    for(int i=temp.size()-1;i>=0;i--)
    {
        int p = temp[i].first;
        ll x = temp[i].second;
        if(p==-1)
        {
            last_update = max(last_update,x);
        }
        else
        {
            if(ans[p]==-1)
            {
                ans[p] = max(x,last_update);
            }
        }
        
    }
    for(int i=0;i<n;i++)
    {
        if(ans[i]==-1)
        {
            ans[i] = max(a[i],last_update);
            
        }
        cout<<ans[i]<<" ";
    }
}
