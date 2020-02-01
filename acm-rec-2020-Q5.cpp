#include <bits/stdc++.h>
using namespace std;
int level[1000005];
int vis[1000005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    level[a[0]] = 1;
    set <int> s;
    s.insert(a[0]);
    for(int i=1;i<n;i++)
    {
        auto it = s.lower_bound(a[i]);
        if(it == s.begin())
        {
            level[a[i]] = level[*it] + 1;
        }
        else{
            it--;
            int num = *it;
            if(vis[num]==1)
            {
                it++;
                level[a[i]] = level[*it] + 1;
            }
            else
            {
                vis[num] = 1;
                level[a[i]] = level[num]+1;
            }
            
        }
        s.insert(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << level[a[i]] << " ";
    }
}