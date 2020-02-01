#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll power(ll x,ll y, ll m)
{
    if(y==0)
        return 1;
    ll p = power(x,y/2,m);
    p = (p*p)%m;
    if(y%2!=0)
    {
        p = (p*x)%m;
    }
    return p;
}
int main ()
{
    ll x,n;
    cin>>x>>n;
    set <ll> v;
    for(int i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            int fl=0;
            for(int j=2;j*j<=i;j++)
            {
                if(i%j==0)
                    {fl=1;break;}
            }
            if(fl==0 && i!=1)
            {
                v.insert(i);
            }
            fl=0;
            for(int j=2;j*j<=(x/i);j++)
            {
                if((x/i)%j==0)
                    {fl=1;break;}
            }
            if(fl==0)
            {
                v.insert(x/i);
            }
        }
    }
    ll ans = 1,m=1e9+7;
    for(auto i:v)
    {
        // cout<<i<<" - ";
        ll p = i;
        while(p<=n)
        {
            // cout<<p<<" ";
            ll x = n/p;
            (ans *= power(i,x,m))%=m;
            if(p > n/i)
                break;
            p = p*i;
        }
        // cout<<"\n";
    }
    cout<<ans;
}