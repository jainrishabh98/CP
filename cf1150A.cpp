#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,m,r;
    cin>>n>>m>>r;
    int a,b=1001,s=0;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        b = min(b,a);
    }
    for(int i=0;i<m;i++)
    {
        cin>>a;
        s = max(s,a);
    }
    int sh = r/b;
    cout<<max(r,sh*s+r%b);
    
}