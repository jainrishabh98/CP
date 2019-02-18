#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
int main ()
{
    ll n,m,k;
    cin>>n>>m>>k;
    ll a[n];
    for(int i=0;i<n;i++)    cin>>a[i];
    sort(a,a+n);
    ll temp = k*a[n-1] + a[n-2];
    ll t = m/(k+1);
    ll ans = temp*t;
    ans += (m%(k+1))*a[n-1];
    cout<<ans;
}