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
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        ll a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        k = min(k, m - 1);
        int l, p = m - 1 - k;
        ll ans = 1;
        for (int i = 0; i <= k; i++)
        {
            l = n - 1 - (k - i);
            ll an = 1e9;
            for (int j = 0; j <= p; j++)
            {
                // cout << i << " " << l << " " << i + j << " " << l - p + j << "\n";
                an = min(an, max(a[i + j],a[l - p + j]));
            }
            // cout<<i<<" "<<l<<" "<<an<<"\n";
            ans = max(ans, an);
        }
        cout << ans << "\n";
    }
}