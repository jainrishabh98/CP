#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll p[n];
    for(int i=0;i<n;i++)
        cin>>p[i];
    sort(p,p+n);
    ll m = p[n-1];
    ll cnt = 1;
    ll sum = 0;
    for(int i=0;i<n-1;i++)
    {
        sum += p[i];
        if(sum > m)
            break;
        cnt++;
    }
    cout<<cnt;
}