#include <bits/stdc++.h>
using namespace std;
struct st
{
    int x, y, z;
};
bool comp(st a, st b)
{
    return (a.z < b.z);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, m;
        cin >> n >> k >> m;
        int cnt[k+1];
        int ans[n];
        int req[n];
        int prevv[k+1];
        map<int, int> mp;
        st s[m];
        deque<int> q;
        for (int i = 1; i <= k; i++)
        {
            mp[i] = 1;
            cnt[i] = 0;
            prevv[i] = -1;
        }
        for (int i = 0; i < n; i++)
        {
            ans[i] = -1;
            req[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> s[i].x >> s[i].y >> s[i].z;
            s[i].z--;
        }
        sort(s, s + m, comp);
        int fll = 0, prev = -1;
        for (int i = 0; i < m; i++)
        {
            ans[s[i].z] = s[i].x;
            req[s[i].z] = s[i].y;
            if (s[i].z == prev)
            {
                fll = 1;
                break;
            }
            prev = s[i].z;
        }
        if (fll == 1)
        {
            cout << "No\n";
            continue;
        }
        int fr = 0;
        int fl = 0;
        for (int i = 0; i < n; i++)
        {
            if (ans[i] == -1)
            {
                fr++;
                q.push_back(i);
            }
            else
            {
                if (fr + cnt[ans[i]] < req[i] - 1)
                {
                    fl = 1;
                    break;
                }
                int l = (req[i] - 1 - cnt[ans[i]]);
                for (int j = 1; j <= l; j++)
                {
                    int p = q.back();
                    q.pop_back();
                    if (p <= prevv[ans[i]])
                    {
                        fl = 1;
                        break;
                    }
                    ans[p] = ans[i];
                    cnt[ans[i]]++;
                }
                if (fl == 1)
                    break;
                fr -= l;
                cnt[ans[i]]++;
                prevv[ans[i]] = i;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (ans[i] == -1)
            {
                if (mp.empty())
                {
                    fl = 1;
                    break;
                }
                auto j = mp.begin();
                ans[i] = j->first;
            }
            else
            {
                if (mp.find(ans[i]) != mp.end())
                {
                    mp.erase(ans[i]);
                }
            }
        }
        if (fl == 1)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
            for (int i = 0; i < n; i++)
            {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
    }
}