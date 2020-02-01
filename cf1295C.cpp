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
        string s, t, c;
        cin >> s >> t;
        int n = t.length();
        int m = s.length();
        vector<int> v[26];
        int fl = 0;
        for (int i = 0; i < m; i++)
        {
            int in = s[i] - 'a';
            v[in].push_back(i);
        }
        int i = 0;
        int j = 0;
        int ans = 1;
        while (i < n)
        {
            int in = t[i] - 'a';
            if (v[in].empty())
            {
                fl = 1;
                break;
            }
            else
            {
                int ind = lower_bound(v[in].begin(), v[in].end(), j) - v[in].begin();
                if (ind == v[in].size())
                {
                    ans++;
                    j = v[in][0];
                }
                else
                {
                    j = v[in][ind];
                }
            }
            i++;
            j++;
        }
        if (fl == 0)
            cout << ans << "\n";
        else
        {
            cout << -1 << "\n";
        }
    }
}