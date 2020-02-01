#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,k,q;
    cin>>n>>m>>k>>q;
    pair<ll,ll> s[k];
    ll lm[n];
    memset(lm,n+1,sizeof(lm));
    ll rm[n];
    memset(rm,0,sizeof(rm));
    for(int i=0;i<k;i++)
    {
        cin>>s[i].first>>s[i].second;
        rm[s[i].first] = max(rm[s[i].first],s[i].second);
        lm[s[i].first] = min(lm[s[i].first],s[i].second);
    }
    int b[q];
    for(int i=0;i<q;i++)
    {
        cin>>b[i];
    }
    sort(b,b+q);
    ll ans = 0;
    ll x = 1,y = 1;
    ll dp[n+1][2];
    for(int i=1;i<=n;i++)
    {
        if(i%2==0)
        {

        }
        else
        {
         
        }
        
    }

}