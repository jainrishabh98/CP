#include <bits/stdc++.h>
using namespace std;
typedef int ll;
const ll num = 750001;
ll dp[num], a[num];
vector<ll> v[num];
void sieve(ll n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + i; j <= n; j += i)
        {
            v[j].push_back(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    sieve(num-1);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x, mx = 1;
        cin >> n;
        for (int i = 1; i < num; i++)
        {
            a[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            a[x] = 1;
            mx = max(mx, x);
        }
        long long ans = 0, m = 1e9 + 7;
        for (int i = 1; i <= mx; i++)
        {
            if (a[i] == 1)
            {
                dp[i]=1;
                for (auto j : v[i])
                {
                    if (a[j] == 1)
                    {
                        (dp[i] += dp[j]) %= m;
                    }
                }
                (ans += dp[i]) %= m;
            }
        }
        cout << ans << "\n";
    }
}