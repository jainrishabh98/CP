#include<bits/stdc++.h>
using namespace std;
bool vis[505][505];
int a[505][505];
int k;
void dfs(int x,int y)
{
    vis[x][y] = true;
    if(a[x+1][y]==0 && !vis[x+1][y]) 
            dfs(x+1,y);
    if(a[x-1][y]==0 && !vis[x-1][y]) 
            dfs(x-1,y);
    if(a[x][y+1]==0 && !vis[x][y+1]) 
            dfs(x,y+1);
    if(a[x][y-1]==0 && !vis[x][y-1]) 
            dfs(x,y-1);
    if(k>0)
    {
        a[x][y]=2;
        k--;
    }
}
int main ()
{
    int n,m;
    cin>>n>>m>>k;
    char x;
    int sx,sy;
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=m+1;j++)
        {
            if(i==0 || j==0 || i==n+1 || j==m+1)
                a[i][j] = 1;
            else
            {
            cin>>x;
            if(x=='.') {a[i][j] = 0;sx=i;sy=j;}
            else a[i][j] = 1;
            }
        }
    }
    dfs(sx,sy);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==0)
                cout<<'.';
            else if(a[i][j]==1)
                cout<<'#';
            else
                cout<<'X';
        }
        cout<<"\n";
    }
}