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
        int fl = 0;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == '?')
            {
                if (i == 0)
                    s[i] = 'a';
                else
                    s[i] = (s[i - 1] - 'a' + 1) % 3 + 'a';
                if (s[i] == s[i + 1])
                {
                    s[i] = (s[i] - 'a' + 1) % 3 + 'a';
                }
            }
            if (s[i] == s[i + 1])
                fl = 1;
        }
        int i = s.length() - 1;
        if (s[i] == '?')
        {
            if (i == 0)
                s[i] = 'a';
            else
                s[i] = (s[i - 1] - 'a' + 1) % 3 + 'a';
        }
        if (fl == 1)
            cout << -1 << "\n";
        else
        {
            cout << s << "\n";
        }
    }
}