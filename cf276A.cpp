#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,k;
    cin>>n>>k;
    int a,b;
    int ans = -1e9 - 1;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        if(b<=k)
        {
            ans = max(ans,a);
        }
        else
        {
            ans = max(ans,a-(b-k));
        }
    }
    cout<<ans;
}