#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, h;
    cin >> n >> h;
    pair<int, int> a[n];
    int ans[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
        ans[i] = 1;
    }
    int mn=0;
    if (n > 2)
    {
        sort(a, a + n);
        mn=a[n - 1].first + a[n - 2].first - a[0].first - a[1].first;
        if (max(a[n - 2].first + a[n - 1].first, a[n - 1].first + a[0].first + h) - min(a[0].first + a[1].first + h, a[2].first + a[1].first) < a[n - 1].first + a[n - 2].first - a[0].first - a[1].first)
        {
            mn = max(a[n - 2].first + a[n - 1].first, a[n - 1].first + a[0].first + h) - min(a[0].first + a[1].first + h, a[2].first + a[1].first);
            ans[a[0].second] = 2;
        }
    }
    cout<<mn<<"\n";
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}