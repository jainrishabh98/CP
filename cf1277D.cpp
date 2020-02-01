#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int nn;
        cin >> nn;
        string s;
        int fl1=0,fl2=0;
        unordered_map<string, int> ump, mp;
        for (int i = 0; i < nn; i++)
        {
            cin >> s;
            if (s[0] != s[s.length() - 1])
            {
                if (s[0] == '1')
                {
                    ump[s] = i + 1;
                }
                else
                {
                    mp[s] = i + 1;
                }
            }
            else
            {
                if (s[0] == '1')
                {
                    fl1=1;
                }
                else
                {
                    fl2=1;
                }
            }
            
        }
        int n = mp.size();
        int m = ump.size();
        if(n==0 && m==0)
        {
            if(fl1 + fl2 == 2)
            {
                cout<<-1<<"\n";
                continue;
            }
            else
            {
                cout<<0<<"\n\n";
                continue;
            }
            
        }
        vector<int> ans;
        if (n > m)
        {
            for (auto i : mp)
            {
                if (n - m <= 1)
                    break;
                s = i.first;
                reverse(s.begin(), s.end());
                if (ump.find(s) == ump.end())
                {
                    ans.push_back(i.second);
                    n--;
                    m++;
                }
            }
        }
        else
        {
            for (auto i : ump)
            {
                if (m - n <= 1)
                    break;
                s = i.first;
                reverse(s.begin(), s.end());
                if (mp.find(s) == mp.end())
                {
                    ans.push_back(i.second);
                    n++;
                    m--;
                }
            }
        }
        if (abs(n - m) > 1)
            cout << -1 << "\n";
        else
        {
            cout << ans.size() << "\n";
            for(auto i:ans)
            {
                cout<<i<<" ";
            }
            cout<<"\n";
        }
    }
}