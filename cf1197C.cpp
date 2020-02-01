#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int n,k;
    cin>>n>>k;
    ll a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector <ll> v;
    for(int i=1;i<n;i++)
        v.push_back(a[i] - a[i-1]);
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    ll ans = 0;
    for(int i=0;i<k-1;i++)
    {
        ans += v[i];
    }
    ans += a[0];
    ans = a[n-1] - ans;
    cout<<ans;
}