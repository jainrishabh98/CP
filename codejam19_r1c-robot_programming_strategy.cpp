#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int l = 1; l <= t; l++)
    {
        int a;
        cin >> a;
        string s[a];
        int vis[a];
        for (int i = 0; i < a; i++)
        {
            cin >> s[i];
            vis[i] = 0;
        }
        string ans;
        set<char> c;
        int flag = 0;
        for (int j = 0; j <= 499; j++)
        {
            c.clear();
            for (int i = 0; i < a; i++)
            {
                if (vis[i] == 0)
                {
                    c.insert(s[i][j % s[i].length()]);
                }
            }
            if (c.size() == 3)
            {
                flag = 1;
                break;
            }
            else if (c.size() == 1)
            {
                char x = *c.begin();
                char fchar;
                if (x == 'R')
                    fchar = 'P';
                else if (x == 'P')
                    fchar = 'S';
                else if (x == 'S')
                    fchar = 'R';
                ans.push_back(fchar);
                break;
            }
            else
            {
                char fchar, x, y;
                auto itr = c.begin();
                x = *itr;
                itr++;
                y = *itr;
                if(x=='P' && y=='R')
                    fchar = x;
                else if(x=='P' && y=='S')
                    fchar = y;
                else if(x=='R' && y=='S')
                    fchar = x;
                ans.push_back(fchar);
                for (int i = 0; i < a; i++)
                {
                    if (s[i][j % s[i].length()] != fchar)
                    {
                        vis[i] = 1;
                    }
                }
            }
        }
        if(flag==1)
        {
            cout<<"Case #"<<l<<": IMPOSSIBLE\n";
        }
        else
        {
            cout<<"Case #"<<l<<": "<<ans<<"\n";
        }
    }
}