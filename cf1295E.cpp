#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_NN = 200005;
int segtree[4 * MAX_NN];
int arr[MAX_NN];
int qlow, qhigh, p, diff;
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
    if (p < low || p > high)
        return;
    if (low != high)
    {
        int mid = (low + high) / 2;
        update(low, mid, 2 * pos + 1);
        update(mid + 1, high, 2 * pos + 2);
        segtree[pos] = min(segtree[2 * pos + 1], segtree[2 * pos + 2]);
    }
    else
    {
        segtree[pos] += diff;
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
    for(int i=0;i<n;i++)
        cin>>a[i];
    arr[0] = a[0];
    for (int i = 1; i < n; i++)
        arr[i] = arr[i - 1] + a[i];
    build(0, n - 1, 0);
    for (int i = 0; i < n; i++)
    {
        int poss = mp[i];
    }
}