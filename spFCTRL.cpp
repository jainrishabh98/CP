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
        ll m =1;
        ll ans = 0;ll i = 5;
        while(m!=0)
        {
            m = n/i;
            i = i*5;
            ans += m;
        }
        cout<<ans<<"\n";
    }
    return 0;
}