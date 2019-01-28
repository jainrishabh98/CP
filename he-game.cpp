#include<bits/stdc++.h>
using namespace std;
int t,n,x,c;
int v[101];
int ans[101];
queue <int> q;
int flag;
void bfs(int u)
{
    ans[u]=0;
    q.push(u);
    while(!q.empty())
    {
        int r = q.front();
        q.pop();
        if(r==c)
        {
            flag = 1;
        }
        for(int i=1;i<=x;i++)
        {   
            if(ans[v[r+i]] > (ans[r] + 1) && r+i<=100)
                {
                    ans[v[r+i]] = ans[r] + 1;
                    q.push(v[r+i]);
                }
        }
    }
}
int main ()
{   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>c;
        for(int i=1;i<=100;i++)
        {
            v[i] = i;
            ans[i] = 1e9+7;
        }
        flag=0;
        int temp,z;
        for(int i=0;i<n;i++)
        {
            cin>>temp>>z;
            v[temp] = z;
        }
        bfs(1);
        if(flag==1)
            cout<<ans[c]<<"\n";
        else
            cout<<"-1\n";

    }

}