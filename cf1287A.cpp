#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        string s;
        cin >> s;
        int ans = 0, len = 0;
        reverse(s.begin(), s.end());
        for (int i = 0; i < k; i++)
        {
            if (s[i] == 'A')
            {
                ans = max(ans, len);
                len = 0;
            }
            else
            {
                len++;
            }
        }
        cout << ans << "\n";
    }
}