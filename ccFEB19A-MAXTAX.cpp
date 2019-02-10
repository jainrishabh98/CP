#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[100005][205];
ll anss[100005][205];
ll best[100005][205];
ll m = 1e9 + 21;
ll n, e, k, ans, an, cnt;
ll t, a, c;
vector<bool> v, rv, vf;
vector<vector<ll>> g, rg, h;
vector<set<ll>> gg;
vector<ll> b;
ll leader[100005];
stack<ll> st;
void dfs(ll u)
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
void my_dfs(ll u)
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
void dffs(ll u)
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
        for (ll j : gg[u])
        {
            if (!vf[j])
            {
                dffs(j);
            }
            for (int f = 0; f <= k; f++)
            {
                temp[f] = max(temp[f], best[j][f]);
            }
        }
        for (int y = 0; y <= k; y++)
        {
            for (int f = 0; f <= y; f++)
            {
                best[u][y] = max(best[u][y], anss[u][f] + temp[y-f]);
            }
        }
    }
}

void initialise()
{
    v.assign(n, false);
    rv.assign(n, false);
    g.assign(n, vector<ll>());
    rg.assign(n, vector<ll>());
    b.assign(n, 0);
    memset(dp, 0, sizeof(dp));
    memset(anss, 0, sizeof(anss));
    memset(best, 0, sizeof(best));
    memset(leader, 0, sizeof(leader));
}
void cllr()
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
        ll mn[e][2];
        initialise();
        cnt = 0;
        for (ll i = 0; i < n; i++)
            cin >> b[i];
        for (ll i = 0; i < e; i++)
        {
            cin >> a >> c;
            a--;
            c--;
            mn[i][0] = a;
            mn[i][1] = c;
            g[a].push_back(c);
            rg[c].push_back(a);
        }
        for (ll i = 0; i < n; i++)
        {
            if (!v[i])
                dfs(i);
        }
        while (!st.empty())
        {
            ll x = st.top();
            st.pop();
            if (!rv[x])
            {
                h.push_back(vector<ll>());
                my_dfs(x);
                cnt++;
            }
        }
        for (ll i = 0; i < cnt; i++)
        {
            sort(h[i].begin(), h[i].end());
            // for(auto j:h[i])
            //     cout<<j<<" ";
            // cout<<"\n";
        }
        gg.assign(cnt, set<ll>());
        vf.assign(cnt, false);
        for (ll i = 0; i < e; i++)
        {
            ll l1 = leader[mn[i][0]];
            ll l2 = leader[mn[i][1]];
            if (l1 != l2)
            {
                gg[l1].insert(l2);
            }
        }
        for (ll i = 0; i < cnt; i++)
        {
            ll l = h[i].size();
            for (ll j = 0; j <= k; j++)
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
        for (ll i = 0; i < cnt; i++)
        {
            if (!vf[i])
                dffs(i);
        }
        ans = 0;
        for (ll i = 0; i < cnt; i++)
        {
            for (ll j = 0; j <= k; j++)
            {
                ans = max(ans, best[i][j]);
            }
        }
        cout << ans % m << endl;
        cllr();
    }
}