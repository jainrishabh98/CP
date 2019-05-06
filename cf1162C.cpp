#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int x[k];
    for (int i = 0; i < k; i++)
        cin >> x[i];
    int ans = 3 * n - 2;
    int vis[n + 2] = {0};
    for (int i = k - 1; i >= 0; i--)
    {
        if (vis[x[i]] != 0)
        {
            ans += vis[x[i]];
        }
        vis[x[i]] = 1;
        ans--;
        if (vis[x[i] + 1] != 0)
        {
            ans--;
            vis[x[i]]++;
        }
        if (vis[x[i] - 1] != 0)
        {
            ans--;
            vis[x[i]]++;
        }
    }
    cout<<ans;
}