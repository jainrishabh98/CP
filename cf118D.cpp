#include <bits/stdc++.h>
using namespace std;
int MOD = 1e8;
int n1, n2, k1, k2;
long long memo[101][101][11][11];

long long C(int f, int h, int kf, int kh)
{
    if (memo[f][h][kf][kh] == -1)
    {
        long long ans;
        if (f + h == 0)
            ans = 1;
        else
        {
            ans = 0;
            if (f > 0 && kf > 0)
                ans = (ans + C(f - 1, h, kf - 1, k2)) % MOD;
            if (h > 0 && kh > 0)
                ans = (ans + C(f, h - 1, k1, kh - 1)) % MOD;
        }
        memo[f][h][kf][kh] = ans;
    }
    return memo[f][h][kf][kh];
}

int main()
{
    memset(memo, -1, sizeof memo);
    cin >> n1 >> n2 >> k1 >> k2;
    cout << C(n1, n2, k1, k2) << endl;
    return 0;
}