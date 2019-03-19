#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ipair;
vector <ipair> g[100005];
int d[505][505];
bool vis[100005];
int mp[100005];
int c[505],s[505];
void my_dfs(int u)
{
    vis[u] = true;
    for (auto j:g[u])
    {
        if(!vis[j.first] && j.second==0)
        {  
            my_dfs(j.first);
        }
    }
}
int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            d[i][j] = 1000000000;
        }
    }
    for(int i=0;i<k;i++) cin>>c[i];
    s[0] = 1;
    for(int i=1;i<k;i++) s[i] = s[i-1] + c[i-1];
    int jj = 1;
    for(int i=0;i<k;i++)
    {   int y = c[i];
        while(y--)
        {
            mp[jj] = i;
            jj++;
        }
    }
    int u,v,x;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>x;
        g[u].push_back(make_pair(v,x));
        g[v].push_back(make_pair(u,x));
        d[mp[u]][mp[v]] = min(d[mp[u]][mp[v]],x);
        d[mp[v]][mp[u]] = min(d[mp[v]][mp[u]],x);
    }
    for(int i=0;i<k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            vis[j] = false;
        }
        my_dfs(s[i]);
        for(int j=s[i]+1;j<s[i]+c[i];j++)
        {
            if(!vis[j])
                {
                    cout<<"No";
                    return 0;
                }
        }        
    }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            for(int r=0;r<k;r++)
            {
                if(d[j][r] > d[j][i] + d[i][r])
                {
                    d[j][r] = d[j][i] + d[i][r];
                }
            }
        }
    }
    cout<<"Yes\n";
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(i==j)
                cout<<"0 ";
            else if(d[i][j]==1000000000)
                cout<<"-1 ";
            else
                cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }
}