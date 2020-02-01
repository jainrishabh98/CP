#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll m;
    cin >> m;
    ll a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(b, b + n);
    sort(a, a + n);
    ll ans = 1e12;
    for (int i = 0; i < n; i++)
    {
        int fl = 0;
        int j = 0;
        ll diff = (b[j] - a[i] + m) % m;
        j++;
        for (; j < n; j++)
        {
            int p = (i + j) % n;
            if (((b[j] - a[p] + m) % m) != diff)
            {
                fl = 1;
                break;
            }
        }
        if (fl == 0)
        {
            ans = min(ans, diff);
        }
    }
    cout << ans;
}