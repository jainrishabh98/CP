#include<bits/stdc++.h>
using namespace std;
set <int> clr[100005];
int main ()
{
    int n,m;
    cin>>n>>m;
    int c[n+1];
    for(int i=1;i<=n;i++)    cin>>c[i];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(c[a]!=c[b])
        {
            clr[c[a]].insert(c[b]);
            clr[c[b]].insert(c[a]);
        }
    }
    int mx=0;
    int ans=INT_MAX;
    for(int i=1;i<=n;i++)
    {   
        if(clr[c[i]].size()>mx)
            {mx = clr[c[i]].size();ans=c[i];}
        else if (clr[c[i]].size()==mx)
            {ans = min(ans,c[i]);}
        
    }
    cout<<ans<<"\n";
    return 0;
}