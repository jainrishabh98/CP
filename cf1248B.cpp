#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll a[n];
    ll s1 = 0,s2 = 0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s2 += a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n/2;i++)
    {
        s1 += a[i];
    }
    s2 -= s1;
    cout<<s1*s1 + s2*s2;
    
}