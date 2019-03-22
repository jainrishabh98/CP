#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> at, def;
    string s;
    int x;
    int st[m];
    for (int i = 0; i < n; i++)
    {
        cin >> s >> x;
        if (s[0] == 'A')
        {
            at.push_back(x);
        }
        else
        {
            def.push_back(x);
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> st[i];
    }
    sort(st, st + m);
    reverse(st, st + m);
    sort(at.begin(), at.end());
    reverse(at.begin(), at.end());
    sort(def.begin(), def.end());
    reverse(def.begin(), def.end());
    int ans1 = 0;
    for (int i = at.size() - 1; i >= 0; i--)
    {
        int sum = 0;
        int j = i;
        for (int k = 0; k < m; k++)
        {
            for (; j < at.size(); j++)
            {
                if (at[j] <= st[k])
                {
                    sum += st[k] - at[j];
                    j++;
                    break;
                }
            }
        }
        ans1 = max(ans1, sum);
    }
    int vis[m] = {0};
    int cnt = 0;
    for (int i = def.size() - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (st[j] > def[i] && vis[j] == 0)
            {
                vis[j] = 1;
                cnt++;
                break;
            }
        }
    }
    if (cnt == def.size())
    {
        int sum = 0, fl = 0;
        int j = 0;
        for (int k = 0; k < m; k++)
        {
            if (vis[k] == 0)
            {
                for (; j < at.size(); j++)
                {
                    if (at[j] <= st[k])
                    {
                        sum += st[k] - at[j];
                        vis[k] = 1;
                        j++;
                        fl++;
                        break;
                    }
                }
            }
        }
        if (fl == at.size())
        {
            for (int i = 0; i < m; i++)
            {
                if (!vis[i])
                    sum += st[i];
            }
            ans1 = max(ans1, sum);
        }
    }
    cout << ans1;
}