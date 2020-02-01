#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> g[500005];
int vis[500005];
int cn = 0;
void dfs(int u,int p)
{
    vis[u] = 1;
    cn++;
    for(auto i:g[u])
    {
        if(!vis[i])
            dfs(i,u);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int l, r;
    set<int> sl, sr;
    map<int, int> mp, ump;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        mp[r] = l;
        ump[l] = i + 1;
        sl.insert(l);
        sr.insert(r);
    }
    int cnt = 0;
    for (auto i : sr)
    {
        auto ind = sl.upper_bound(i);
        int lll = mp[i];
        auto in = sl.lower_bound(lll);
        int d = ump[*in];
        in++;
        while (in != ind)
        {
            int pp = ump[*in];
            g[pp].push_back(d);
            g[d].push_back(pp);
            cnt++;
            if (cnt == n)
                break;
            in++;
        }
        if (cnt == n)
            break;
        sl.erase(lll);
    }
    if(cnt == n)
    {
        cout<<"NO";
        return 0;
    }
    dfs(1,0);
    if(cn==n)
        cout<<"YES";
    else
        cout<<"NO";
}