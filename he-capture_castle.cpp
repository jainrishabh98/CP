#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,t;
int a[1001][1001];
int tt[1001][1001];
queue <pair<int,int> > q;
# define mp make_pair
void bfs(int i,int j)
{
    
    tt[i][j] = a[i][j];
    q.push(mp(i,j));
    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if(r+1<=m && tt[r][c] + a[r+1][c] < tt[r+1][c] )
        {
                tt[r+1][c] = tt[r][c] + a[r+1][c];
                q.push(mp(r+1,c));
            
        }
        if(r-1>0 && tt[r][c] + a[r-1][c] < tt[r-1][c])
        {
            
                tt[r-1][c] = tt[r][c] + a[r-1][c];
                q.push(mp(r-1,c));
            
        }
        if(c-1>0 && tt[r][c] + a[r][c-1] < tt[r][c-1])
        {
                tt[r][c-1] = tt[r][c] + a[r][c-1];
                q.push(mp(r,c-1));
            
        }
        if(c+1<=n && tt[r][c] + a[r][c+1] < tt[r][c+1])
        {
                tt[r][c+1] = tt[r][c] + a[r][c+1];
                q.push(mp(r,c+1));
            
        }
       
    }
}
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            // vis[i][j]=0;
            tt[i][j]=INT_MAX;
        }
    }
    int et;
    cin>>x>>y>>et;
    bfs(1,1);
    if(tt[x][y]<=et)
    {
        cout<<"YES\n"<<et - tt[x][y]<<"\n";
    }
    else cout<<"NO\n";
    }
}