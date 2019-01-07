#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    string s;
    cin >> s;
    cin >> k;
    int cn = 0, sn = 0, l = s.length();
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '*')
            sn++;
        else if (s[i] == '?')
            cn++;
    }
    int mn = l - 2*(sn + cn);
    if (k < mn)
    {
        cout << "Impossible\n";
        
    }
    else
    {
        int diff = k - mn;
        if (sn > 0)
        {
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == '*' )
                    {
                        while(diff--)
                        {
                            cout<<s[i-1];
                        }
                    }
                else if (s[i] == '?')
                    continue;
                else
                    cout<<s[i];
            }
            cout<<"\n";
        }
        else
        {   if(k>(l-cn))
                {
                    cout<<"Impossibe\n";return 0;
                }
            int cnt=0;
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == '?' )
                {
                    continue;
                }
                else
                    {cout<<s[i];
                    cnt++;
                    if(cnt==k) break;
                    }
            }
            cout<<"\n";
        }
    }
    return 0;
}