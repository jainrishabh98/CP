#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m = 1e7 + 7;
ll fp(ll x, ll y)
{
    if(y==0)   return 1;
    else if(y==1)   return x;
    else if (y%2==0)   return (fp(x,y/2)*fp(x,y/2))%m;
    else    return (((fp(x,y/2)*fp(x,y/2))%m)*x)%m;
}
int main ()
{   
    ll n,k;
    cin>>n>>k;
    while(n!=0 && k!=0)
    {
        
        ll a = 2*fp(n-1,k);
        ll b = fp(n,k);
        ll c = 2*fp(n-1,n-1);
        ll d = fp(n,n);
        ll ans = (a+b+c+d)%m; 
        cout<<ans<<"\n";
        cin>>n>>k;
    }
    return 0;
}