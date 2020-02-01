#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int, int> par;
ll dp[100005][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int m, n = 1;
        par.clear();
        par[0] = 0;
        dp[0][0] = 0;
        dp[0][1] = 0;
        cin >> m;
        while (m--)
        {
            int tt, v;
            cin >> tt >> v;
            if (tt == 0)
            {
                dp[n][0] = dp[n][1] = 0;
                par[n] = v;
                int i = v, pp = 0;
                while (par[i] != i)
                {
                    dp[i][pp]++;
                    pp = pp^1;
                    i = par[i];
                }
                dp[i][pp]++;
                n++;
            }
            else
            {
                ll odd = dp[v][0];
                ll even = dp[v][1];
                even++;
                ll ans = (odd * (odd - 1)) / 2 + (even * (even - 1)) / 2;
                cout << ans << "\n";
            }
        }
    }
}