#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,x,y;
    cin>>n>>x>>y;
    int a[n];
    int cnt=0;
    for(int i=0;i<n;i++)
       { cin>>a[i]; if(a[i]<=x) cnt++;}
    if(y<x)
    {
        cout<<n;
    }
    else
    {
        cout<<(int)(ceil(cnt/2.0));
    }
}