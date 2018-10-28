#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m = 1e9 + 7;
int main ()
{
    ll t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        ll temp = (k*(k+1))/2;
        if (temp>n)
            cout<<"-1\n";
        else if (temp==n)
            cout<<"0\n";
        else
        {
            ll c = n - temp;
            ll v = c/k;
            c = c%k;
            ll a[k];
            for(ll i=0;i<k;i++)
                a[i]=i+1+v;
            ll i = k-1;
            while(c!=0)
            {
                a[i]++;
                c--;
                i--;
            }
            ll ans =1;
            for(ll i=0;i<k;i++)
                {
                    ans = (ans*((a[i]*(a[i]-1))%m))%m;
                }
            cout<<ans<<"\n";
        }
    }
    return 0;
}