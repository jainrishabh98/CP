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
        int diff = k-mn;int flag=0;
        if (sn > 0)
        {
            for (int i = 0; i < s.length(); i++)
            {
                if(s[i+1] == '*' && i<s.length())
                    {   if(flag==1) continue;
                        else
                        {
                        flag=1;
                        while(diff!=0)
                        {   diff--;
                            cout<<s[i];
                        }
                        }
                    }
                else if (s[i] == '?' || (s[i+1]=='?' && i<s.length() ) ||s[i]=='*')
                    continue;
                else
                    cout<<s[i];
            }
            cout<<"\n";
        }
        else
        {   if(k>(l-cn))
                {
                    cout<<"Impossible\n";return 0;
                }
           
            for (int i = 0; i < s.length(); i++)
            {
                if(s[i+1] == '?' && i<s.length())
                {   if(diff==0) continue;
                    else{
                    cout<<s[i];diff--;
                    }
                }
                else if (s[i] == '?' )
                {
                    continue;
                }
                else
                    {cout<<s[i];
                    }
            }
            cout<<"\n";
        }
    }
    return 0;
}