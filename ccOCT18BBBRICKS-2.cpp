#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m = 1e9 + 7;
ll power(ll x, ll y) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 

int main ()
{
    int t;
    ll n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(k>n)
            cout<<"0\n";
        
        else if(k==1)
        {
            cout<<(n+n)%m<<"\n";
        }
        else if(n==1)
            cout<<"0\n";
        else if (k==n)
             cout<<"2\n";
        else
        {
        ll ans = 2*(n-k+1);
        ll temp = ans;
        for (int i=1;i<=k-1;i++)
        {   if((i+1)>(n-k+1))
                break;
            else
            {
            ll a = (temp*(k-i))%m;
            ll b = ((n-k-i+1)*2)%m;
            ll c = i*(i+1);
            b = (a*b)%m;
            ll inv = power(c,m-2);
            temp = (b*inv)%m;
            ans = (ans + temp)%m;
            //cout<<b<<" "<<c<<" "<<" "<<ans<<"\n";
            }
        }
        cout<<ans<<"\n";
        }
    }
    return 0;
}