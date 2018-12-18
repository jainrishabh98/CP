#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
ll rev(ll n)
{
    ll ans = 0;
        while(n!=0){
            ll a = n%10;
            ans = ans*10 + a;
            n=n/10;
        }
    return ans;
}
int main ()
{
    int n;
    cin>>n;
    while(n--)
    {
        ll x,y;
        cin>>x>>y;
        x = rev(x);
        y= rev(y);
        cout<<rev(x+y)<<"\n";

    }
    return 0;
}