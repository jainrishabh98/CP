#include <bits/stdc++.h>
using namespace std;
const int N = 20;
const int M = (1 << N) + 55;
const int INF = int(1e9) + 100;
int a, n;
string s;
int cnt[N][N];
int dp[M];
int cntBit[M];

int main()
{
    cin >> n >> a >> s;

    int B = (1 << a) - 1;
    for (int i = 1; i < s.size(); ++i)
    {
        ++cnt[s[i] - 'a'][s[i - 1] - 'a'];
        ++cnt[s[i - 1] - 'a'][s[i] - 'a'];
    }
    for (int i = 0; i < M; ++i)
        dp[i] = INF;
    dp[0] = 0;
    for (int msk = 0; msk <= B; ++msk)
    {
        cntBit[msk] = 1 + cntBit[msk & (msk - 1)];
        for (int i = 0; i < a; ++i)
        {
            if ((msk >> i) & 1)
                continue;
            int d1 = 0, d2 = 0;
            for (int j = 0; j < a; j++)
            {
                if(i==j) continue;
                if ((msk >> j) & 1)
                    d1 += cnt[i][j];
                else
                    d2 += cnt[i][j];
            }
            dp[msk|(1 << i)] = min(dp[msk|(1 << i)] , dp[msk] + cntBit[msk] * (d1 - d2));
        }
    }

    cout << dp[B] << endl;
    return 0;
}