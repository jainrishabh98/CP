#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,m;
    cin>>n>>m;
    int x,y;
    int r[n+1]={0};
    int c[n+1]={0};
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        r[x] = 1;
        c[y] = 1;
    }
    int cnt = 0;
    for(int i=2;i<=n-1;i++)
    {
        if(r[i]==0)
            cnt++;
        if(c[i]==0)
            cnt++;
    }
    if(n%2!=0)
    {
        if(r[(n+1)/2]==0 && c[(n+1)/2]==0)
            cnt--;
    }
    cout<<cnt;
}