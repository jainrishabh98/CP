#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll a[n],b[n],c[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    ll s= 0;
    for(int i=0;i<n;i++)
    {
        ll d = -a[i] - 1;
        // cout<<d<<" ";
        d = (d^b[i]);
        d = (d&c[i]);
        // cout<<d<<"\n";
        if(d > 0)
        {
            s += ((a[i]^b[i]) + d);
        }
        else
        {
            s += ((a[i]^b[i]) - (c[i]&(-c[i])));
        }
        
    }
    cout<<s;
}