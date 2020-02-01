#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m = 1e9 + 7;
ll mod(ll x)
{
    if (x >= m)
        x -= m;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int x, l = 0;
        cin >> x;
        string s, c;
        cin >> s;
        ll ans = s.length();
        while (ans < x)
        {
            for (int k = 0; k < s[l] - '1'; k++)
            {
                for (int j = l + 1; j < ans; j++)
                {
                    s.push_back(s[j]);
                }
            }
            ans = ans + (s[l] - '1') * (ans - l - 1);
            l++;
        }
        while (l < x)
        {
            ans = mod(ans + mod((s[l] - '1') * mod(ans - l - 1 + m)));
            l++;
        }
        cout << ans << "\n";
    }
}