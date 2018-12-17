#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    // cout<<s;
    int fl1 = 0, fl2 = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == 'A' && s[i + 1] == 'B' && fl1 == 0)
        {
            fl1 = 1;
            i++;
        }
        else if (s[i] == 'B' && s[i + 1] == 'A' && fl2 == 0 && fl1!=0)
        {
            fl2 = 1;
            i++;
        }
    }
    if (fl1 == 1 && fl2 == 1)
        cout << "YES\n";
    else
    {
        int fl1 = 0, fl2 = 0;
        for (int i = 0; i < s.length() - 1; i++)
        {

            if (s[i] == 'B' && s[i + 1] == 'A' && fl2 == 0)
            {
                fl2 = 1;
                i++;
            }
            else if (s[i] == 'A' && s[i + 1] == 'B' && fl1 == 0 && fl2!=0)
            {
                fl1 = 1;
                i++;
            }
        }
        if (fl1 == 1 && fl2 == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}