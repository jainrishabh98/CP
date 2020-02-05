#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_NN = 100010;
ll segtree[4 * MAX_NN];
ll lazy[4 * MAX_NN];
ll qlow, qhigh, l, r, diff;
void update(ll low, ll high, ll pos)
{
    int mid = (low + high) / 2;
    if (lazy[pos] != 0)
    {
        segtree[pos] += (high-low+1)*lazy[pos];
        if (low != high)
        {
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (r < low || l > high)
        return;
    if (low >= l && high <= r)
    {
        segtree[pos] += (high-low+1)*diff;
        if (low != high)
        {
            lazy[2 * pos + 1] += diff;
            lazy[2 * pos + 2] += diff;
        }
        return ;
    }
    update(low, mid, 2 * pos + 1);
    update(mid + 1, high, 2 * pos + 2);
    segtree[pos] = segtree[2 * pos + 1] + segtree[2 * pos + 2];
}
ll query(ll low, ll high, ll pos)
{
    int mid = (low + high) / 2;
    if (lazy[pos] != 0)
    {
        segtree[pos] += (high-low+1)*lazy[pos];
        if (low != high)
        {
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (qlow > high || qhigh < low) // no overlap
        return 0;
    if (qlow <= low && qhigh >= high) // total overlap
        return segtree[pos];
    return (query(low, mid, 2 * pos + 1) + query(mid + 1, high, 2 * pos + 2));
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
        ll n, c, p, q, v, x;
        cin >> n >> c;
        memset(segtree, 0, sizeof(segtree));
        memset(lazy, 0, sizeof(lazy));
        while (c--)
        {
            cin >> x >> p >> q;
            if (x == 0)
            {
                cin >> v;
                l = max((ll)0,p - 1), r = min(n-1,q - 1);
                diff = v;
                update(0, n - 1, 0);
            }
            else
            {
                qlow = max((ll)0,p - 1);
                qhigh = min(n-1,q - 1);
                cout << query(0, n - 1, 0) << "\n";
            }
        }
        
    }
}