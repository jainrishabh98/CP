#include<bits/stdc++.h>
using namespace std;
vector <vector <int> > to;
vector <vector <int> > from;
int store[3001][3001];
int main ()
{
    int n,m;
    cin>>n>>m;
    to.assign(n+1,vector <int>());
    from.assign(n+1,vector<int> ());
    memset(store,0,sizeof(store));
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        to[a].push_back(b);
        from[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {   
        for(auto j:from[i])
        {   
            for(auto k:to[i])
            {
                if(j!=k)
                    store[j][k]++;
            }
            
        }
        
    }
    long long int r = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            r += (store[i][j]*(store[i][j]-1))/2;
        }
    }
    cout<<r<<"\n";
    return 0;
}