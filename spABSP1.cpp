#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        ll temp = 0;
        ll ans = 0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            temp = (n-i-1)*(a[i+1] - a[i]) + temp;
            ans += temp;
        }
        cout<<ans<<"\n";
    }
    return 0;
}