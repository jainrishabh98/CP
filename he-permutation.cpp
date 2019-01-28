#include<bits/stdc++.h>
using namespace std;
unordered_map <string,int> vis;
queue <string> q;
string s,ans,v,temp;
int n,x;
void bfs()
{
    vis[s]=0;
    q.push(s);
    while(!q.empty())
    {
        v = q.front();
        q.pop();
        if(v==ans)
            {cout<<vis[ans];return;}
        for(int i=2;i<=n;i++)
        {   
            temp = v;
            reverse(temp.begin(),temp.begin()+i);
            if(vis.find(temp)==vis.end())
            {
                vis[temp]=vis[v]+1;
                q.push(temp);
            }
        }
    }
}
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)    {cin>>x;s.push_back((char)(x+'0'));ans.push_back((char)(i+1+'0'));}
    bfs();
}