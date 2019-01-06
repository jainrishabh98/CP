#include<bits/stdc++.h>
using namespace std;
struct st{
    int u,v;
};
bool comp (st a, st b)
{
    return (a.u == b.u) ? (a.v < b.v) : (a.u < b.u);
}
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,q,k,flag,v1,v2;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        st s[m];
        set<int> z;
        for(int i=0;i<m;i++)
        {
            cin>>s[i].u>>s[i].v;
            z.insert(s[i].u);z.insert(s[i].v);
        }
        cin>>q;
        while(q--)
        {
            cin>>k;
            map <int,int> vis;
            flag=0;
            int x,y;
            for(int i=0;i<k;i++)
                {cin>>x>>y;
                auto index = z.lower_bound(x);
                while(index!=z.end() && *index<=y)
                    {vis[*index]=1;index++;}
                }
            for(int i=0;i<m;i++)
            {   
                if(vis[s[i].u]==1 && vis[s[i].v]==1) {flag=1;break;}
            }
            if(flag==1)
                cout<<"NO\n";
            else
                cout<<"YES\n";

        }
    }
    return 0;
}