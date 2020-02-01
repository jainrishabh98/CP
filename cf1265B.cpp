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
        int n;
        cin >> n;
        int p[n];
        int st = -1, l = -1, r = n;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            if (p[i] == 1)
            {
                st = i;
            }
        }
        l = st - 1;
        r = st + 1;
        set<int> s;
        int ans[n + 1] = {0};
        int cnt = 1;
        s.insert(1);
        ans[1] = 1;
        while (cnt != n)
        {
            if (l == -1)
            {
                s.insert(p[r]);
                r++;
            }
            else if (r == n)
            {
                s.insert(p[l]);
                l--;
            }
            else if(p[l] > p[r])
            {
                s.insert(p[r]);
                r++;
            }
            else
            {
                s.insert(p[l]);
                l--;
            }
            if (*s.rbegin() == s.size())
                    ans[s.size()] = 1;
            cnt++;
        }
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i];
        }
        cout << "\n";
    }
}