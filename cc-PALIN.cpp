#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int l = s.length();
        int i = (l - 1) / 2, j = l / 2;
        while (i >= 0)
        {
            if (s[i] == '9' && s[j] == '9')
            {
                i--;
                j++;
            }
            else
            {
                break;
            }
        }
        if (i == -1)
        {
            cout << 1;
            for (int i = 0; i < l - 1; i++)
                cout << 0;
            cout << 1 << "\n";
        }
        else
        {
            if (s[i] <= s[j])
            {
                s[i]++;
                s[j] = s[i];
                i++;
                while (i < j)
                {
                    s[i] = '0';
                    i++;
                }
                cout<<s<<"\n";
            }
            else
            {
                for(;j<l;j++)
                {
                    s[j] = s[i];
                    i--;
                }
                cout<<s<<"\n";
            }
        }
    }
}