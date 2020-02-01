#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        int c[n];
        vector<int> v[n], p;
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
            for (int j = 0; j < c[i]; j++)
            {
                cin >> x;
                v[i].push_back(x);
            }
            if (c[i] & 1)
            {
                p.push_back(v[i][c[i] / 2]);
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < c[i] / 2; j++)
            {
                ans += v[i][j];
            }
        }
        if (!p.empty())
        {
            sort(p.begin(), p.end());
            for (int i = p.size() - 1; i >= 0; i -= 2)
            {
                ans += p[i];
            }
        }
        cout << ans << "\n";
    }
}