#include<bits/stdc++.h>
using namespace std;
int vis[100001];
long long int a[1001];
int n;
int s,e;
long long int m = 1e5;
queue <int> q;
int flag=0;
void bfs(int u)
{
    vis[u] = 0;
    q.push(u);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        
        for(int i=0;i<n;i++)
        {   
            long long int temp = (v*a[i])%m;
            if(!vis[temp])
            {   
                vis[temp]=vis[v]+1;
                if(temp == e) {flag=1;return ;}
                q.push(temp);
            }
        }
        

    }
}
int main ()
{   
    cin>>s>>e>>n;
    for(int i=0;i<n;i++)    cin>>a[i];
    if(s==e) {cout<<"0";return 0;}
    bfs(s);
    if(flag==0) cout<<"-1";
    else    cout<<vis[e];
}