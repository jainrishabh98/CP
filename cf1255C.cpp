#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int q[n - 2][3];
    set<int> v[n + 1];
    int vis[n + 1] = {0};
    for (int i = 0; i < n - 2; i++)
    {
        cin >> q[i][0] >> q[i][1] >> q[i][2];
        v[q[i][0]].insert(q[i][1]);
        v[q[i][0]].insert(q[i][2]);
        v[q[i][1]].insert(q[i][2]);
        v[q[i][1]].insert(q[i][0]);
        v[q[i][2]].insert(q[i][0]);
        v[q[i][2]].insert(q[i][1]);
    }
    vector<int> ans;
    int start;
    for (int i = 1; i <= n; i++)
    {
        if (v[i].size() == 2)
        {
            start = i;
            break;
        }
    }
    queue<int> pq;
    pq.push(start);
    vis[start] = 1;
    while (!pq.empty())
    {
        int u = pq.front();
        ans.push_back(u);
        pq.pop();
        priority_queue <ipair, vector <ipair> , greater <ipair> > pqq;
        for (auto i : v[u])
        {
            if (vis[i] == 0)
            {
                int cn = 0;
                for (auto j : v[i])
                {
                    if(vis[j]==0)
                        cn++;
                }
                pqq.push({cn,i});
            }
        }
        while(!pqq.empty())
        {
            pq.push(pqq.top().second);
            pqq.pop();
        }
        for(auto i:v[u])
            vis[i]=1;
    }
    for(auto i:ans)
        cout<<i<<" ";
}