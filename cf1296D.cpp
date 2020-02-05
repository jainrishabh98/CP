#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    ll h[n];
    ll cost[n];
    for (int i = 0; i < n; i++)
        cin >> h[i];
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll p = h[i] % (a + b);
        cout << p << " ";
        if (p == 0)
        {
            p = b;
            cost[i] = ceil(p / ((double)(a)));
        }
        else
        {
            cost[i] = ceil(p / ((double)(a))) - 1;
        }

        // cost[i] = ceil(p / ((double)(a))) - 1;
    }
    cout << "\n";
    sort(cost, cost + n);
    for (int i = 0; i < n; i++)
    {
        // cout << cost[i] << " ";
        if (cost[i] <= k)
        {
            ans++;
            k -= cost[i];
        }
    }
    // cout << "\n";
    cout << ans;
}