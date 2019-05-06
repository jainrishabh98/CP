#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,h,m;
    cin>>n>>h>>m;
    int a[n+1];
    for(int i=1;i<=n;i++)
        a[i] = h;
    int l,r,x;
    for(int i=0;i<m;i++)
    {
        cin>>l>>r>>x;
        for(int j=l;j<=r;j++)
        {
            a[j] = min(a[j],x);
        }
    }
    long long int ans = 0;
    for(int i=1;i<=n;i++)
    {
        ans += a[i]*a[i];
    }
    cout<<ans;
}