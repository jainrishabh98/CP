#include <bits/stdc++.h>
using namespace std;
struct st{
    long long int v,in;
};
bool comp(st a, st b)
{
    return(a.v==b.v) ? (a.in < b.in) : (a.v > b.v);
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    st a[n+1];
    int flag[n+1]={0};
    for(int i=1;i<=n;i++)    {cin>>a[i].v; a[i].in=i;}
    sort(a+1,a+n+1,comp);
    long long int sum = 0;
    for(int i=1;i<=(m*k);i++)
    {
        sum += a[i].v;
        flag[a[i].in]=1;
    }
    cout<<sum<<"\n";
    int cnt=0,cn=0;
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==1)
        {
            cnt++;
            if(cnt==m && cn<k-1)
            {
                cout<<i<<" ";
                cnt=0;
                cn++;
            }
        }
    }
}