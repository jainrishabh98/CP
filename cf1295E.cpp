#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_NN = 200005;
ll segtree[4 * MAX_NN];
ll arr[MAX_NN];
ll qlow, qhigh, l, r, diff;
ll lazy[4 * MAX_NN];
void build(int low, int high, int pos)
{
    if (low == high)
    {
        segtree[pos] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(low, mid, 2 * pos + 1);
    build(mid + 1, high, 2 * pos + 2);
    segtree[pos] = min(segtree[2 * pos + 1], segtree[2 * pos + 2]);
}
void update(int low, int high, int pos)
{
    if (r < low || l > high)
        return;
    if (lazy[pos] != 0)
    {
        segtree[pos] += lazy[pos];
        if (low != high)
        {
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (low >= l && high <= r)
    {
        segtree[pos] += diff;
        if (low != high)
        {
            lazy[2 * pos + 1] += diff;
            lazy[2 * pos + 2] += diff;
        }
        return;
    }
    int mid = (low + high) / 2;
    update(low, mid, 2 * pos + 1);
    update(mid + 1, high, 2 * pos + 2);
    segtree[pos] = min(segtree[2 * pos + 1], segtree[2 * pos + 2]);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int p[n];
    ll a[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
        mp[p[i]] = i;
    }
    for (int i = 0; i < n; i++)
        cin >> a[i];
    arr[0] = a[0];
    for (int i = 1; i < n; i++)
        arr[i] = arr[i - 1] + a[i];
    build(0, n - 2, 0);
    ll ans = min(segtree[0], a[0]);
    // cout<<ans<<"\n";
    for (int i = 0; i < n - 1; i++)
    {
        int poss = mp[i];
        l = 0;
        r = poss - 1;
        diff = a[poss];
        if (r >= l)
            update(0, n - 2, 0);
        l = poss;
        r = n - 2;
        diff = -a[poss];
        update(0, n - 2, 0);
        ans = min(ans, (ll)segtree[0]);
    }
    cout << min(ans, a[n - 1]);
}