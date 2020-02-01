#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
bool check(char x)
{
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll l;
        cin >> l;
        string s;
        vector<string> v1, v2;
        for (int i = 0; i < l; i++)
        {
            cin >> s;
            int fl = 0;
            for (int j = 0; j < s.length() - 1; j++)
            {
                if (!check(s[j]))
                {
                    if ((!check(s[j + 1])) || (j + 2 < s.length() && (!check(s[j + 2]))))
                    {
                        fl = 1;
                        break;
                    }
                }
            }
            if (fl == 0)
                v1.push_back(s);
            else
                v2.push_back(s);
        }
        ll n = v1.size();
        ll m = v2.size();
        ll fxa[26] = {0};
        ll xa[26] = {0};
        for (int i = 0; i < n; i++)
        {
            s = v1[i];
            set<int> ss;
            for (int j = 0; j < s.length(); j++)
            {
                fxa[s[j] - 'a']++;
                ss.insert(s[j] - 'a');
            }
            for (auto j : ss)
            {
                xa[j]++;
            }
        }
        ll fxb[26] = {0};
        ll xb[26] = {0};
        for (int i = 0; i < m; i++)
        {
            s = v2[i];
            set<int> ss;
            for (int j = 0; j < s.length(); j++)
            {
                fxb[s[j] - 'a']++;
                ss.insert(s[j] - 'a');
            }
            for (auto j : ss)
            {
                xb[j]++;
            }
        }
        ld p1 = 0;
        for (int i = 0; i < 26; i++)
        {
            if (xb[i] != 0)
            {
                p1 -= log(xb[i]);
                p1 += m*log(fxb[i]);
            }
            if (xa[i] != 0)
            {
                p1 += log(xa[i]);
                p1 -= n*log(fxa[i]);
            }
        }
        p1 = exp(p1);
        if (p1 > 1e7)
        {
            cout << "Infinity\n";
            continue;
        }
        cout << fixed;
        cout << setprecision(7) << p1 << "\n";
    }
}