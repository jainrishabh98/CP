#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m = 998244353;
ll power(ll x, ll y) 
{ 
    ll res = 1;   
    while (y > 0) 
    {  
        if (y & 1) 
            res = (res*x)%m;  
        y = y>>1; 
        x = (x*x)%m; 
    } 
    return res; 
}
int main ()
{
    ll n;
    cin>>n;
    ll p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    ll po100[n];
    ll pre[n];
    pre[0] = p[0];
    po100[0] = 1;
    for(int i=1;i<n;i++)
    {
        po100[i] = (100*po100[i-1])%m;
        pre[i] = (pre[i-1]*p[i])%m;
    }
    ll f=0,d=0;
    for(int i=0;i<n;i++)
    {
        ll tmp = ((100 - p[i])*po100[n-1-i])%m;
        if(i>0)
        {
            tmp = (tmp*pre[i-1])%m;
        }
        (d += tmp)%=m;
        (f += tmp*(i+1))%=m;
    }
    (f += (pre[n-1]*n)%m)%=m; // numerator
    ll c = (100*po100[n-1])%m;
    c = (c - d + m)%m; // denominator
    ll gc = __gcd(f,c);
    f /= gc;
    c /= gc;
    c = power(c,m-2);
    ll ans = (f*c)%m;
    cout<<ans;
}