#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<pair<int, int>, int> mp;
        int x = 0, y = 0;
        int l = -1, r = -1, ans = n + 2;
        mp[{0, 0}] = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
                x--;
            else if (s[i] == 'R')
                x++;
            else if (s[i] == 'D')
                y--;
            else if (s[i] == 'U')
                y++;
            if (mp.find({x, y}) != mp.end())
            {
                int xx = mp[{x, y}];
                if (i - xx < ans)
                {
                    l = xx + 1;
                    r = i;
                    ans = i - xx;
                }
            }
            mp[{x, y}] = i;
        }
        if(l==-1)
        {
            cout<<-1<<"\n";
        }
        else
        {
            cout<<l+1<<" "<<r+1<<"\n";
        }
        
    }
}