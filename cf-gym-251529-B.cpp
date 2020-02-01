#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll vis[1001];
ll req[1001];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    cin>>k>>n;
    ll c[k];
    ll rem = 0;
    for(int i=0;i<k;i++)
    {
        cin>>c[i];
        if(c[i]==-1)
        {
            rem++;
        }
        else
        {
            vis[c[i]]++;
        }
    }
    ll r = k/n;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0) continue;
        ll p = vis[i]%r;
        if(rem < p)
        {
            cout<<"No";
            return 0;
        }
        req[i] += p;
        rem -= p;
    }
    cout<<"Yes\n";
    for(int i=0;i<k;i++)
    {
        if(c[i]==-1)
        {

        }
        else
        {
            
        }
        
    }

