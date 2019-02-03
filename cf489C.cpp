#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, s;
    cin >> m >> s;
    int c=s;
    string ans, a;
    if (s == 0 && m == 1)
    {
        cout << "0 0";
        return 0;
    }
    if (s == 0 || s > 9 * m)
    {
        cout << "-1 -1";
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 9; j >= 0; j--)
        {
            if (s - j >= 0 && s - j <= 9 * (m - i))
            {
                s -= j;
                ans.push_back((char)(j + '0'));
                break;
            }
        }
    } 
    s=c;
    for (int i = 1; i < m; i++)
    {
        for (int j = 9; j >= 0; j--)
        {
            if (s - j >= 1 && s - j <= 9 * (m - i))
            {
                s -= j;
                a.push_back((char)(j + '0'));
                break;
            }
        }
    }
    a.push_back((char)(s+'0'));
    reverse(a.begin(),a.end());
    cout << a << " " << ans;
}