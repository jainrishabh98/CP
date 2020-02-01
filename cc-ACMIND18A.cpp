#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        pair<int, int> v[50];
        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '.')
            {
                v[cnt].first = i;
                v[cnt].second = s[i] - '0';
                cnt++;
            }
        }
        int fl = 0;
        for (int i = 0; i < cnt - 1; i++)
        {
            if (v[i].first + v[i].second >= v[i + 1].first - v[i + 1].second)
            {
                fl = 1;
                break;
            }
        }
        if (fl == 0)
            cout << "safe\n";
        else
        {
            cout << "unsafe\n";
        }
    }
}
