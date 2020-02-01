#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st
{
    int l, r, d;
};
bool comp(st x, st y)
{
    return (x.l == y.l) ? (x.r > y.r) : (x.l < y.l);
}
int main()
{
    int m, n, k, t;
    cin >> m >> n >> k >> t;
    int a[m];
    for (int i = 0; i < m; i++)
        cin >> a[i];
    sort(a, a + m);
    st s[k];
    for (int i = 0; i < k; i++)
    {
        cin >> s[i].l >> s[i].r >> s[i].d;
    }
    sort(s, s + k, comp);
    int low = 0;
    int ans = 0;
    int high = m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int tm = 0;
        int prev = 0;
        for (int i = 0; i < k; i++)
        {
            if (s[i].d > a[mid])
            {
                if (s[i].l <= prev)
                {
                    if (s[i].r > prev)
                    {
                        tm += 2 * (s[i].r - prev);
                        prev = s[i].r;
                    }
                }
                else
                {
                    tm += 2 * (s[i].r - s[i].l + 1);
                    prev = s[i].r;
                }
            }
        }
        tm += (n + 1);
        if (tm <= t)
        {
            ans = m - mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans;
}