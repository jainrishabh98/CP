#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> g[1505];
ll v[1505], m, n, ans = 0;
void rec(int x)
{
    if (x == m + 1)
    {
        ll res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] == 1)
                res++;
        }
        ll inc = 0;
        for (int i = 1; i <= m; i++)
        {
            ll cnt = 0;
            for (auto j : g[i])
            {
                if (v[j] == 0)
                    cnt++;
            }
            cnt = min(cnt, (ll)2);
            inc = max(inc, cnt);
        }
        ans = max(ans, res + inc);
    }
    else
    {
        rec(x + 1);
        for (auto i : g[x])
        {
            if (!v[i])
            {
                v[i] = 1;
                rec(x + 1);
                v[i] = 0;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll k, x, y;
    cin >> m >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
    }
    rec(1);
    cout << ans;
}