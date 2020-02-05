#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_NN = 50005;
struct node
{
    ll t = -1e12, b = -1e12, l = -1e12, r = -1e12;
};
node segtree[4 * MAX_NN];
ll arr[MAX_NN];
int qlow, qhigh;
void build(int low, int high, int pos)
{
    if (low == high)
    {
        segtree[pos].t = arr[low];
        segtree[pos].l = arr[low];
        segtree[pos].r = arr[low];
        segtree[pos].b = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(low, mid, 2 * pos + 1);
    build(mid + 1, high, 2 * pos + 2);
    segtree[pos].t = segtree[2 * pos + 1].t + segtree[2 * pos + 2].t;
    segtree[pos].b = max(max(segtree[2 * pos + 1].b, segtree[2 * pos + 2].b), segtree[2 * pos + 1].r + segtree[2 * pos + 2].l);
    segtree[pos].l = max(segtree[2 * pos + 1].l, segtree[2 * pos + 1].t + segtree[2 * pos + 2].l);
    segtree[pos].r = max(segtree[2 * pos + 2].r, segtree[2 * pos + 2].t + segtree[2 * pos + 1].r);
}
node query(int low, int high, int pos)
{
    node pr;
    if (qlow <= low && qhigh >= high) // total overlap
        return segtree[pos];
    if (qlow > high || qhigh < low) // no overlap
        return pr;
    int mid = (low + high) / 2;
    node lef = query(low, mid, 2 * pos + 1);
    node rig = query(mid + 1, high, 2 * pos + 2);
    pr.l = max(lef.l,lef.t + rig.l);
    pr.r = max(rig.r,rig.t + lef.r);
    pr.t = lef.t + rig.t;
    pr.b = max(max(lef.b,rig.b),lef.r+rig.l);
    return pr;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(0, n - 1, 0);
    int m;
    cin >> m;
    while (m--)
    {
        cin >> qlow >> qhigh;
        qlow--;
        qhigh--;
        node ans = query(0,n-1,0);
        cout<<ans.b<<"\n";
    }
}