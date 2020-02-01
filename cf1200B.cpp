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
        int n, m, k;
        cin >> n >> m >> k;
        int h[n];
        for (int i = 0; i < n; i++)
            cin >> h[i];
        int fl = 0;
        for (int i = 0; i < n - 1; i++)
        {
            m += h[i] - max(0, (h[i + 1] - k));
            if (m < 0)
            {
                fl = 1;
                break;
            }
        }
        if (fl == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
