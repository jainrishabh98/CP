#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    int n, h;
    cin >> n >> h;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int mn=0;
    if (n > 2)
    {
        sort(a, a + n);
        mn =  min(max(a[n - 2] + a[n - 1], a[n - 1] + a[0] + h) - min(a[0] + a[1] + h, a[2] + a[1]) , a[n - 1] + a[n - 2] - a[0] - a[1]);
    }
    cout<<mn;
}