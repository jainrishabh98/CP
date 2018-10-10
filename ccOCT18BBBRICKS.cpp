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
        ll N = n+n;
        if(k>n)
            cout<<"0\n";
        
        else if(k==1)
        {
            cout<<N%m<<"\n";
        }
        else if(n==1)
            cout<<"0\n";
        else if (k==n)
             cout<<"2\n";
        else
        {
            // debug
            ll f1=1;
            
            ll f3=1,f4=1;
            ll temp1 =1,temp2 =1,temp3=1;
            for (int i = 1; i<= (k-2); i++)
            {   
                f1 = (f1*i)%m;
                temp3 = (temp3*(N-i-3))%m;
                temp1 = (temp1*(N-k+i))%m;
                temp2 = (temp2*(N-k+i-1))%m;

            }
            for (int i = 1; i<= k; i++)
            {   
                f3 = (f3*i)%m;
                f4 = (f4*(N-i+1))%m;

            }
            
            ll inv = power(f1,m-2);
            temp1 = (temp1*inv)%m;
            temp2 = (2*temp2*inv)%m;
            temp3 = (temp3*inv)%m;
            temp3 = ((3*n - 5)*temp3)%m;
            inv = power(f3,m-2);
            ll total = (f4*inv)%m;
            ll sum = (temp1 + temp2 +temp3)%m;
            ll ans = (total - sum + m)%m;
            cout<<ans<<"\n";
            
        }
    }
    return 0;
}