#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[100001][202];
ll anss[100001][202];
ll m = 1e9 + 21;
ll n, e, k, ans, an, cnt;
ll t, a, c;
vector<bool> v, rv, vf;
vector<vector<int>> g, rg, h;
vector<set<int>> gg;
vector<int> b;
int leader[100001];
stack<int> st;
void dfs(int u)
{
    v[u] = true;
    for (auto j = g[u].begin(); j != g[u].end(); j++)
    {
        if (!v[*j])
        {
            dfs(*j);
        }
    }
    st.push(u);
}
void my_dfs(int u)
{
    h[cnt].push_back(b[u]);
    leader[u] = cnt;
    rv[u] = true;
    for (auto j = rg[u].begin(); j != rg[u].end(); j++)
    {
        if (!rv[*j])
        {
            my_dfs(*j);
        }
    }
}
void dffs(int u)
{
    vf[u] = true;
    for (auto j : gg[u])
    {
        if (!vf[j])
        {
            dffs(j);
        }
        ll l = h[u].size();
        for (int f = 0; f <= k; f++)
        {
            if (f >= l)
            {
                dp[u][f] = max(dp[u][f], anss[j][k - f]);
            }
            else
            {
                ll q = h[u][f];
                dp[u][f] = max(dp[u][f], q * (l - f) + anss[j][k - f]);
            }
            if (f == 0)
                anss[u][f] = dp[u][f];
            else
                anss[u][f] = max(dp[u][f], anss[u][f - 1]);
        }
    }
}

void initialise()
{
    v.assign(n, false);
    rv.assign(n, false);
    g.assign(n, vector<int>());
    rg.assign(n, vector<int>());
    b.assign(n, 0);
    memset(dp, 0, sizeof(dp));
    memset(anss, 0, sizeof(anss));
    memset(leader,0,sizeof(leader));
}
void clear()
{
    h.clear();
    g.clear();
    gg.clear();
    rg.clear();
    v.clear();
    vf.clear();
    rv.clear();
    b.clear();
}
int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> e >> k;
        int mn[e][2];
        initialise();
        cnt = 0;
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < e; i++)
        {
            cin >> a >> c;
            a--;
            c--;
            mn[i][0] = a;
            mn[i][1] = c;
            g[a].push_back(c);
            rg[c].push_back(a);
        }
        for (int i = 0; i < n; i++)
        {
            if (!v[i])
                dfs(i);
        }
        while (!st.empty())
        {
            int x = st.top();
            st.pop();
            if (!rv[x])
            {
                h.push_back(vector<int>());
                my_dfs(x);
                cnt++;
            }
        }
        for (int i = 0; i < cnt; i++)
        {
            sort(h[i].begin(), h[i].end());
            // for(auto j:h[i])
            //     cout<<j<<" ";
            // cout<<"\n";
        }
        gg.assign(cnt, set<int>());
        vf.assign(cnt,false);
        for (int i = 0; i < e; i++)
        {
            int l1 = leader[mn[i][0]];
            int l2 = leader[mn[i][1]];
            if (l1 != l2)
            {
                gg[l1].insert(l2);
            }
        }
        for (int i = 0; i < cnt; i++)
        {
            ll l = h[i].size();
            for (int j = 0; j <= k; j++)
            {
                if (j >= l)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    c = h[i][j];
                    dp[i][j] = (c * (l - j));
                }
                if (j == 0)
                    anss[i][j] = dp[i][j];
                else
                    anss[i][j] = max(dp[i][j], anss[i][j - 1]);
            }
        }
        for (int i = 0; i < cnt; i++)
        {   
            if(!vf[i])
                dffs(i);
        }
        ans = 0;
        for(int i=0;i<cnt;i++)
        {
            ans = max(ans,anss[i][k]);
        }
        cout<<ans%m<<"\n";
        clear();
    }
}