#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, x, y;
    cin >> n >> m;
    int cnt[5005] = {0};
    int mn[5005];
    set <int> g[5005];
    for (int i = 1; i <= n; i++)
    {
        mn[i] = 5001;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        g[x].insert(y);
        cnt[x]++;
    }
    for(int i=1;i<=n;i++)
    {   
        if(g[i].empty()) continue;
        int k = i;
        while (1)
        {
            if(binary_search(g[i].begin(),g[i].end(),k))
            {
                mn[i] = k;
                break;
            }
            k++;
            if (k > n)
                k = 1;
        }
    }
    int mx = *max_element(cnt + 1, cnt + n + 1);
    int ans = n * (max(0, mx - 1));
    int temp = 0;
    // cout<<'h';
    for (int i = 1; i <= n; i++)
    {
        
        int k = i, fl = 0;
        int mbb = ans;
        while (1)
        {
            if (cnt[k]=mx)
            {
                
            }
            if (k == temp)
            {
                fl = 1;
            }
            k++;
            mbb++;
            if (k > n)
                k = 1;
        }
        // cout<<'h';
    }
}