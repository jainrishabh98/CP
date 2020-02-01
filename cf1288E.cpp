#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bit[300005][2];
void update(ll x, ll y, int k)
{
    while (x <= 300000)
    {
        bit[x][k] += y;
        x += (x & (-x));
    }
}
ll query(ll x, int k)
{
    ll s = 0;
    while (x > 0)
    {
        s += bit[x][k];
        x -= (x & (-x));
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, x;
    cin >> n >> m;
    ll pos[n + 1], mx[n + 1], mn[n + 1], tm[n + 1];
    for (int i = 1; i <= n; i++)
    {
        pos[i] = mx[i] = mn[i] = i;
        tm[i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        if (tm[x] != 0)
        {
            pos[x] += query(i - 1, 0) - query(tm[x], 0);
            update(tm[x], -1, 0);
        }
        else
        {
            mn[x] = 1;
            pos[x] += query(n, 1) - query(x, 1);
            update(x, 1, 1);
        }
        tm[x] = i;
        update(tm[x], 1, 0);
        mx[x] = max(mx[x], pos[x]);
        pos[x] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (tm[i] == 0)
            pos[i] += query(n, 1) - query(i, 1);
        else
            pos[i] += query(m, 0) - query(tm[i], 0);
        mx[i] = max(mx[i], pos[i]);
        cout << mn[i] << " " << mx[i] << "\n";
    }
}