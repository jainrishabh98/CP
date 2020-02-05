#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st
{
    ll l, r, p;
};
bool comp(st x, st y)
{
    return (x.r < y.r);
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
        int n;
        cin >> n;
        st s[n];
        ll dp[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i].l >> s[i].r >> s[i].p;
            s[i].r += s[i].l;
            dp[i] = 0;
        }
        sort(s, s + n, comp);
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back(s[i].r);
        }
        dp[0] = s[0].p;
        for (int i = 1; i < n; i++)
        {
            int ind = upper_bound(v.begin(), v.end(), s[i].l) - v.begin();
            ind--;
            dp[i] = max(s[i].p, dp[i - 1]);
            if (ind >= 0)
                dp[i] = max(dp[i], s[i].p + dp[ind]);
        }
        cout << dp[n - 1] << "\n";
    }
}