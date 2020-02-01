#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    if (k == n)
    {
        cout << 1;
        return 0;
    }
    ll po, an;
    ll low = 2, high = n, mid, ans = -1;
    if (high % 2 != 0)
        high--;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (mid % 2 != 0)
            mid--;
        ll md = mid;
        an = 2;
        po = 4;
        mid *= 2;
        while (mid + po <= n + 1)
        {
            an += po;
            po *= 2;
            mid *= 2;
        }
        an += max((ll)0, n - mid + 1);
        if (an >= k)
        {
            ans = max(ans, md);
            low = md + 2;
        }
        else
            high = md - 2;
    }
    low = 1;
    high = n;
    if (high % 2 == 0)
        high--;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (mid % 2 == 0)
            mid--;
        ll md = mid;
        an = 1;
        po = 2;
        mid *= 2;
        while (mid + po <= n + 1)
        {
            an += po;
            po *= 2;
            mid *= 2;
        }
        an += max((ll)0, n - mid + 1);
        if (an >= k)
        {
            ans = max(ans, md);
            low = md + 2;
        }
        else
            high = md - 2;
    }
    cout << ans;
}