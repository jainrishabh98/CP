#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k, mx = 0, sum = 0;
    cin >> n >> k;
    ll m[n];
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
        mx = max(mx, m[i]);
        sum += m[i];
    }
    if (sum < k)
    {
        cout << -1;
        return 0;
    }
    ll low = 1, high = mx + 1, mid, num;
    while (low <= high)
    {
        mid = (low + high) / 2;
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (m[i] / mid);
        }
        if (sum >= k)
        {
            num = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << num;
}
