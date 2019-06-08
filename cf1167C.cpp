#include<bits/stdc++.h>
using namespace std;
vector <int> g[500005];
int vis[500005];
int ans[500005];
int cnt = 0;
stack <int> st;
void dfs(int u)
{
    cnt++;
    st.push(u);
    vis[u] = 1;
    for(auto i:g[u])
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
}
int main ()
{
    int n,m,k,l,a;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>k;
        if(k==0) continue;
        cin>>l;
        for(int i=2;i<=k;i++)
        {
            cin>>a;
            g[l].push_back(a);
            g[a].push_back(l);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cnt = 0;
            dfs(i);
            while(!st.empty())
            {
                ans[st.top()] = cnt;
                st.pop();
            }

        }
        cout<<ans[i]<<" ";
    }
    
}