#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,r;
        cin>>a>>b>>c>>r;
        if(a > b)
            swap(a,b);
        ll x = c - r;
        ll y = c + r;
        if(a >= y || b <= x)
            cout<<abs(b-a)<<"\n";
        else
        {
            ll ans = 0;
            if(a < x)
            {
                ans += abs(x - a);
            }
            if( b > y)
            {
                ans += abs(b - y);
            }
            cout<<ans<<"\n";
        }
    }
}