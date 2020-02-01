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
        ll n, m;
        cin >> n >> m;
        pair<ll, ll> a[n];
        ll cost = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            cost += 2 * a[i].first;
            a[i].second = i + 1;
        }
        if (n == 2 || m < n)
        {
            cout << -1 << "\n";
            continue;
        }
        sort(a, a + n);
        cout << cost << "\n";
        if (n != 4)
        {
            for (int i = 1; i < n; i++)
            {
                cout << a[i].second << " " << a[i - 1].second << "\n";
            }
            cout << a[0].second << " " << a[n - 1].second << "\n";
        }
        else
        {
            cout << a[0].second << " " << a[2].second << "\n";
            cout << a[1].second << " " << a[2].second << "\n";
            cout << a[0].second << " " << a[3].second << "\n";
            cout << a[1].second << " " << a[3].second << "\n";
        }
    }
}