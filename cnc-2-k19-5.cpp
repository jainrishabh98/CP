#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int vis[100005];
vector <int> g[100005];
int str[100005];
void my_dfs(int u)
{
    for (auto j:g[u])
    {
        my_dfs(j);
        str[u] += str[j]+1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,root,x,y;
        cin>>n>>k;
        for(int i=1;i<=n-1;i++)
        {
            cin>>x>>y;
            vis[y] = 1;
            g[x].push_back(y);
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
                {
                    root = i;
                    break;
                }
        }
        my_dfs(root);
        sort(str+1,str+n+1);
        ll sum1 = 0,sum2 = 0;
        for(int i=1;i<=n;i++)
        {
            sum1 += str[i];
            ll temp = k + str[i];
            int ind = lower_bound(str+1,str+n+1,temp) - (str);
            ind --;
            sum2 += (n-ind);
        }
        cout<<sum1<<" "<<sum2<<"\n";
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            vis[i]=0;
            str[i]=0;
        }
    }
}