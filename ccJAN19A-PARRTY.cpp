#include<bits/stdc++.h>
using namespace std;
// struct st{
//     int u,v;
// };
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,q,k,flag,v1,v2;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        // st s[m];
        vector <vector <int>> g;
        g.assign(n,vector<int>());
        int j,h; 
        set<int> z;
        for(int i=0;i<m;i++)
        {
            cin>>j>>h;
            g[j].push_back(h);g[h].push_back(j);
            z.insert(j);z.insert(h);
        }
        cin>>q;
        while(q--)
        {
            cin>>k;
            // int vis[n+1]={0};
            vector <int> vis;
            flag=0;
            int x,y;
            for(int i=0;i<k;i++)
                {cin>>x>>y;
                auto index = z.lower_bound(x);
                while(index!=z.end() && *index<=y)
                    {vis.push_back(*index);index++;}
                }
            for(auto i:vis)
            {

            }
            // for(int i=0;i<m;i++)
            // {   
            //     if(vis[s[i].u]==1 && vis[s[i].v]==1) {flag=1;break;}
            // }
            if(flag==1)
                cout<<"NO\n";
            else
                cout<<"YES\n";

        }
    }
    return 0;
}