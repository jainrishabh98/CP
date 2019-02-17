// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// ll dp[100005][205];
ll anss[100005][205];
ll best[100005][205];
ll m = 1e9 + 21;
ll c, ans, cnt;
int t, a, n, e, k;
bool v[100005], rv[100005], vf[100005];
vector<vector<int>> g, rg, h;
vector<set<int>> gg;
int b[100005];
int leader[100005];
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
    if (gg[u].empty())
    {
        for (int f = 0; f <= k; f++)
        {
            best[u][f] = anss[u][f];
        }
    }
    else
    {
        ll temp[k + 1] = {0};
        for (auto j : gg[u])
        {
            if (!vf[j])
            {
                dffs(j);
            }
            for (int f = 0; f <= k; f++)
            {
                if (best[j][f] > temp[f])
                {
                    temp[f] = best[j][f];
                }
            }
        }
        for (int f = 1; f <= k; f++)
        {
            if (temp[f - 1] > temp[f])
            {
                temp[f] = temp[f - 1];
            }
        }
        int l = h[u].size();
        for (int f = 0; f <= min(l-1,k); f++)
        {
            for (int y = f; y <= k; y++)
            {
                if (temp[y-f] + anss[u][f] > best[u][y])
                {
                    best[u][y] = temp[y-f] + anss[u][f];
                }
            }
        }
    }
}
void cllr()
{
    h.clear();
    g.clear();
    gg.clear();
    rg.clear();
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
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            v[i] = false;
            rv[i] = false;
            g.push_back(vector<int>());
            rg.push_back(vector<int>());
        }
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
            vf[i] = false;
            gg.push_back(set<int>());
        }
        int l1, l2;
        for (int i = 0; i < e; i++)
        {
            l1 = leader[mn[i][0]];
            l2 = leader[mn[i][1]];
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
                best[i][j] = 0;
                anss[i][j] = 0;
                c = 0;
                if (j < l)
                {
                    c = h[i][j];
                    c *= (l - j);
                }
                if (j == 0)
                    anss[i][j] = c;
                else if (c > anss[i][j - 1])
                    anss[i][j] = c;
                else
                    anss[i][j] = anss[i][j - 1];
            }
        }
        for (int i = 0; i < cnt; i++)
        {
            if (!vf[i])
                dffs(i);
        }
        ans = 0;
        for (int i = 0; i < cnt; i++)
        {
            for (int y = 0; y <= k; y++)
            {
                if (best[i][y] > ans)
                {
                    ans = best[i][y];
                }
            }
        }
        ans = ans % m;
        cout << ans << '\n';
        cllr();
    }
}