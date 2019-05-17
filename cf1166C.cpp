#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long int v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] = abs(v[i]);
    }
    sort(v,v+n);
    long long int ans = 0;
    for (int i=0;i<n;i++)
    {
        long long int ind = upper_bound(v+i, v+n, 2 * v[i]) - v;
        ans += ind - i - 1;
    }
    cout << ans;
}