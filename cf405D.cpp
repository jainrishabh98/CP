#include <bits/stdc++.h>
using namespace std;
int vis[1000005];
int main()
{
    int n, s = 1000000;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        vis[x[i]] = 1;
    }
    vector<int> leftout;
    for (int i = 1; i <= 1000000; i++)
    {
        if (vis[i] == 0)
        {
            leftout.push_back(i);
        }
    }
    int ss = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (binary_search(leftout.begin(), leftout.end(), s - x[i] + 1))
        {
            ans.push_back(s - x[i] + 1);
            vis[s - x[i] + 1] = 1;
            ss++;
        }
    }
    int cnt = n - ss;
    if (cnt>0)
    {
        for (int i = 1; i <= s; i++)
        {
            if (vis[i] == 0)
            {
                if (binary_search(leftout.begin(), leftout.end(), s+1-i) && vis[s+1-i]==0)
                {
                    
                    ans.push_back(s - i + 1);
                    ans.push_back(i);
                    vis[s - i + 1] = 1;
                    vis[i]=1;
                    cnt -= 2;
                }
            }
            if(cnt==0) break;
        }
    }
    cout << ans.size() << "\n";
    for (auto i : ans)
    {
        cout << i << " ";
    }
}