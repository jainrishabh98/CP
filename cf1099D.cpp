#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector <vector <ll>> v;
bool vis[100005];
ll sum;
ll s[100005];
ll flag;
void my_dfs(int u)
{
    vis[u] = true;
    
    for (auto j= v[u].begin(); j!= v[u].end();j++)
    {
        if(!vis[*j])
        {   if(s[*j] < s[u]) flag=1;
            sum += (s[*j] - s[u]);
            my_dfs(*j);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    ll p[n+1];
    v.assign(n+1,vector <ll>());
    memset(vis,false,sizeof(vis));
    memset(s,0,sizeof(s));
    for(int i=2;i<=n;i++)
    {
        cin>>p[i];
        v[p[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
        cin>>s[i];
      
    for(int i=2;i<=n;i++)
        {
            if(s[i]==-1)
            {
                ll mn = INT_MAX;
                if(v[i].empty())
                    s[i] = s[p[i]];
                else{
                for(auto j:v[i])
                {
                    mn = min(mn,s[j]);
                }
                s[i] = mn;
                }

            }
        }
    
    flag=0;
    sum = s[1];
    my_dfs(1);
    if(flag==1)
        cout<<"-1\n";
    else
        cout<<sum<<"\n";
    return 0;
}