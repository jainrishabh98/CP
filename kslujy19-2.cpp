#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin >> t;
    for (int l = 1; l <= t; l++)
    {

        ll n, g, m;
        cin >> n >> g >> m;
        ll a[g];
        int vis[n];
        int ans[g];
        char c[g];
        vector<int> v[n];
        queue<int> q;
        for(int i=0;i<n;i++)
            vis[i]=0;
        for (int i = 0; i < g; i++)
        {
            cin >> a[i] >> c[i];ans[i]=0;
        }
        for (int i = 0; i < g; i++)
        {
            a[i]--;
            ll temp;
            if (c[i] == 'C')
            {
                temp = (a[i] + m) % n;
                v[temp].push_back(i);
            }
            else
            {
                temp = (a[i] - m + (1000000000 * n)) % n;
                v[temp].push_back(i);
            }
            if (vis[temp] == 0)
                q.push(temp);
            vis[temp] = 1;
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (vis[u] - 1 == m)
                break;
            int l = (u - 1 + n) % n;
            int r = (u + 1) % n;
            for (auto i : v[u])
            {
                if ((vis[l] == 0 || vis[l] == vis[u] + 1) && c[i] == 'C')
                {

                    v[l].push_back(i);
                    if (vis[l] == 0)
                    {
                        vis[l] = vis[u] + 1;
                        q.push(l);
                    }
                }
                if ((vis[r] == 0 || vis[r] == vis[u] + 1) && c[i] == 'A')
                {

                    v[r].push_back(i);
                    if (vis[r] == 0)
                    {
                        vis[r] = vis[u] + 1;
                        q.push(r);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (auto j : v[i])
            {
                ans[j]++;
            }
        }
        cout << "Case #" << l << ": ";
        for (int i = 0; i < g; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}