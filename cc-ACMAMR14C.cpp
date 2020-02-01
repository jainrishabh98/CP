#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[20005][501];
ll a[20005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        a[i] = s[i] - '0';
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll m, l;
        cin >> m >> l;
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j]=0;
            }
        }
        dp[0][a[0]%m] = 1;
        for (int i = 1; i < s.length(); i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x = (j * 10 + a[i]) % m;
                dp[i][x] += dp[i-1][j];
            }
            dp[i][a[i]%m]++;
        }
        ll ans = 0;
        for(int i=0;i<s.length();i++)
        {
            ans += dp[i][l];
        }
        cout<<ans<<"\n";
    }
}