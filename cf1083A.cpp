#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<bool> v;
vector<vector<pair<ll, ll> > > g;
void edge(ll a, ll b, ll wt)
{
    g[a].push_back(make_pair(b, wt));
    g[b].push_back(make_pair(a, wt));
}
ll ans = 0;
ll fn = 0;
ll prnt[300001];
ll dp[300001];
ll w[300001];
ll mx = INT_MIN;
void my_dfs(ll u)
{
    v[u] = true;
    ans += w[u];
    fn = max(fn,ans);
    // ll m1=0,m2=0;
    // cout << u << " ";
       
    // for (vector<pair<ll, ll> >::iterator j = g[u].begin(); j != g[u].end(); j++)
    // {
    //     if (!v[j->first] )
    //     {   ll temp = my_dfs(j->first);
    //         temp-= j->second;

    //             if(temp>=m1)
    //             {
    //                 m2=m1;
    //                 m1=temp;
    //             }
    //             else if(temp>=m2)
    //             {
    //                 m2=temp;
    //             }
            
    //     }
    // }
    // mx=max(mx,m1+m2+w[u]);
    // return m1+w[u];
    for (vector<pair<ll, ll> >::iterator j = g[u].begin(); j != g[u].end(); j++)
    {   
        if (!v[j->first] && w[j->first] >= j->second)
        {   
            prnt[j->first] = prnt[u];
            ans -= j->second;
            my_dfs(j->first);
        }
        
        else if (v[j->first] && dp[prnt[j->first]]!=-1 && dp[prnt[j->first]] >= j->second)
            {ans += dp[j->first]; ans -= j->second;}
        
    }
}

int main()
{
    int n;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    v.assign(n, false);
    g.assign(n, vector<pair<ll, ll> >());
    // int index = -1,mx=-1;
    for (int i = 0; i < n; i++)
        {cin >> w[i]; prnt[i]=i;}
    ll a, b, wt;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> wt;
        edge(a-1, b-1, wt);
    }
    // my_dfs(0);
    // cout<<mx<<"\n";
    for(int i=0;i<n;i++)
    { 
        // v.assign(n, false);
        if(!v[i])
            my_dfs(i);
        dp[i] = ans;
        // fn = max(fn,dp[i]);
        ans=0;            
    }
    cout<<fn<<"\n";
    return 0;
}
