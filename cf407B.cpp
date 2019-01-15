#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
// better soln =  dp[i + 1] = 2dp[i] + 2 - dp[pi]. see tutorial
int main()
{
    ll n, m = 1e9 + 7;
    cin >> n;
    ll p[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    ll cnt[n + 1]={0};
    ll dp[n + 1][n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            else if (j > i)
            {
                if (p[j] == i)
                    dp[j][i] = 1;
            }
            else
            {
                ll temp = 0;
                if ((cnt[i - 1] + 1) % 2 == 0)
                {
                    temp = 1;
                    cnt[i - 1]++;
                }
                else
                {
                    temp = 1 + 1 + dp[p[i - 1]][i - 1];
                    cnt[i - 1] += 2;
                }

                dp[j][i] = (dp[j][i - 1] + temp)%m;
            }
        }
    }
    cout<<(dp[1][n]+1+dp[p[n]][n]+1)%m<<"\n";
    return 0;
}