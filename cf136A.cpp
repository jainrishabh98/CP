#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int p[n+1];
    int ans[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        ans[p[i]] = i;
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
}