#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt;
bool v[100005], rv[100005];
vector<vector<int>> g, rg, h;
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
    h[cnt].push_back(1);
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
void initial(ll c)
{
    h.clear();
    g.clear();
    rg.clear();
    cnt = 0;
    for (int i = 0; i <= c; i++)
    {
        v[i] = false;
        rv[i] = false;
        g.push_back(vector<int>());
        rg.push_back(vector<int>());
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll c, r, a, b;
        cin >> c >> r;
        initial(c);
        for (int i = 1; i <= r; i++)
        {
            cin >> a >> b;
            // a--;b--;
            g[a].push_back(b);
            rg[b].push_back(a);
        }
        for (int i = 1; i <= c; i++)
        {
            if (!v[i])
                dfs(i);
        }
        ll ans = 0;
        h.push_back(vector<int>());
        while (!st.empty())
        {
            int x = st.top();
            st.pop();
            if (!rv[x])
            {
                h.push_back(vector<int>());
                my_dfs(x);
                if (h[cnt].size() > 1)
                    ans += h[cnt].size();
                cnt++;
            }
        }
        cout << ans << "\n";
    }
}