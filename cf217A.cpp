#include<bits/stdc++.h>
using namespace std;
int n;
bool vis[102];
int xx[102];
int yy[102];
void dfs(int j)
{
    vis[j] = true;
    for(int i=0;i<n;i++)
    {
        if((xx[i]==xx[j] || yy[i]==yy[j]) && !vis[i])
        {
            dfs(i);
        }
    }
}
int main ()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>xx[i]>>yy[i];
    }
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt-1;
}