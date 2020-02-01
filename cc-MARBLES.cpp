#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll f=1;
        for(int i=1;i<=k-1;i++)
        {
            f *= (n-k+i);
            f /= i;
        }
        cout<<f<<"\n";
    }
}