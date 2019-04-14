#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        string s;
        string a, b;
        cin >> s;
        int flag = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '4')
            {
                flag = 1;
                a.push_back('3');
                b.push_back('1');
            }
            else
            {
                a.push_back(s[i]);
                if (flag == 1)
                    b.push_back('0');
            }
        }
        cout << "Case #" << j << ": " << a << " " << b << "\n";
    }
}