#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ll n,m,c,x,y,p;
    cin>>n>>m>>c;
    ll s1=0,s2=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>p;
        if(y-m*x-c < 0)
            s1 += p;
        else
            s2 += p;
    }
    cout<<max(s1,s2);
}