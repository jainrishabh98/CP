#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    ll b[n],p[n];
    for(int i=0;i<n;i++)    cin>>b[i];
    
    for(int i=0;i<n-1;i++)
    {
        p[i] = b[i+1] - b[i];
    }
    sort(p,p+n-1);
    ll ans = 0;
    for(int i=0;i<n-k;i++)
    {
        ans += p[i];
    }
    ans += k;
    cout<<ans;
}