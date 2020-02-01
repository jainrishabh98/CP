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
        string s;
        cin >> s;
        int n = s.length();
        int cn[2] = {0};
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                cn[0]++;
            else
                cn[1]++;
        }
        int ans = n;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = i; j < n; j++)
            {
                if (s[j] == s[i])
                {
                    cnt++;
                    ans = min(ans, cn[s[i]-'0'] - cnt + (j - i + 1 - cnt));
                }
            }
        }
        cout<<ans<<"\n";
    }
}