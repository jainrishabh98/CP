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
        int fl = 0;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if ((s[i] - '0') % 2 != 0)
            {
                fl++;
                v.push_back(s[i] - '0');
                if (fl == 2)
                    break;
            }
        }
        if (fl == 2)
            cout <<v[0]<<v[1]<<"\n";
        else
            cout<<-1<<"\n";
    }
}