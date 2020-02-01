#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        if (a.length() > b.length())
        {
            reverse(b.begin(), b.end());
            while (a.length() > b.length())
            {
                b.push_back('0');
            }
            reverse(b.begin(), b.end());
        }
        else if (b.length() > a.length())
        {
            reverse(a.begin(), a.end());
            while (b.length() > a.length())
            {
                a.push_back('0');
            }
            reverse(a.begin(), a.end());
        }
        // cout << a << "\n";
        // cout << b << "\n";
        int cn[2] = {0};
        int mx = 0, c = 0;
        for (int i = 0; i < a.length(); i++)
        {
            if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1'))
            {
                c++;
                if (b[i] == '1')
                    cn[0] = 1;
            }
            else if (a[i] == '1' && b[i] == '1')
            {
                mx = max(mx, c);
                c = 0;
                cn[1] = 1;
                cn[0] = 1;
            }
            else
            {
                c = 0;
            }
        }
        if (cn[0] == 0)
            cout << 0 << "\n";
        else if (cn[1] == 0)
            cout << 1 << "\n";
        else
        {
            cout << mx + 2 << "\n";
        }
    }
}