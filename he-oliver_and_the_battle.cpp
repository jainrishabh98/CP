#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001][1001];
int vis[1001][1001];
queue <pair<int,int> > q;
# define mp make_pair
int bfs(int x,int y)
{   int cnt=0;
    vis[x][y]=1;
    q.push(mp(x,y));
    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        cnt++;
        q.pop();
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(i==0 && j==0)    continue;
                if(r+i>=0 && r+i<n && c+j>=0 && c+j<m && !vis[r+i][c+j] && a[r+i][c+j]==1)
                    {vis[r+i][c+j]=1;q.push(mp(r+i,c+j));}
            }
        }
        
    }
    return cnt;
}
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                {cin>>a[i][j];vis[i][j]=0;}
        }
        int ans1=0,ans2=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                {
                    if(!vis[i][j] && a[i][j]==1)
                    {
                        ans1 = max(ans1,bfs(i,j));
                        ans2++;
                    }
                }
        }
        cout<<ans2<<" "<<ans1<<"\n";
    }
}