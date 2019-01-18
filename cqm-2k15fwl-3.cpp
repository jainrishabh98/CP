#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<vector<int>> g;
struct st{
    int cnt;
    int num;
};
bool comp(st a,st b)
{
    return (a.cnt==b.cnt) ? (a.num > b.num) : (a.cnt > b.cnt);
}
void edge(int a, int b)
{
    g[a].push_back(b);
}
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    g.assign(n+1, vector<int>());
    int val[n+1];
    int x,y;
    int par[n+1];
    st s[n+1];
    for(int i=1;i<=n;i++)
    {
        s[i].cnt = 0;
        s[i].num = -1;
        par[i]=0;
    }
    par[1]=1;
    for(int i=1;i<=n;i++)    cin>>val[i];
    for (int i=1;i<=n-1;i++) 
    {
        cin>>x>>y;
        // cout<<'e';
        par[y] = x;
        edge(x , y);
    }
    vector <int> leaf;
    for(int i=1;i<=n;i++)
    {
        if(g[i].empty())
         leaf.push_back(i);
    }
    for(auto i:leaf)
    {
            s[i].num = i;
            int j = par[i];
            while(par[j]!=j)
            {
                // cout<<j<<" ";
                if(__gcd(val[j],__gcd(val[1],val[i]))==1)
                    s[i].cnt++;
                j = par[j];
            }
            // cout<<"\n";
        
    }
    //  cout<<'h';
    sort(s+1,s+n+1,comp);
    for(int i=1;i<=n;i++)
    {   
        if(s[i].num!=-1)
            cout<<s[i].num<<" ";
    }
    cout<<"\n";
}