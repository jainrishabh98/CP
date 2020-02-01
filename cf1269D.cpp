#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, x, ans = 0;
    cin >> n;
    ll dp[2];
    dp[0] = dp[1] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        ans += (x / 2);
        dp[i % 2] += (x % 2);
    }
    cout << ans + min(dp[0], dp[1]);
}