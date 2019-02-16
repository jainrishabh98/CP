#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,v;
    cin>>n>>v;
    int ans = min(v,n-1);
    for (int i=2;i<=n-v;i++)
    {
        ans += i;
    }
    cout<<ans;
}