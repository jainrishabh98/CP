#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll n,m,k;
    cin>>n>>m>>k;
    ll low = 1,high = n*m;
    while(low<high)
    {
        ll mid = (high+low)/2;
        ll r = 0;
        for (ll i = 1; i <= n; i++)
        {
            r += min(m, mid / i);
        }
        if (r >= k)
            high = mid;
        else
            low = mid + 1;
        cout<<mid<<" "<<r<<"\n";
    }
    cout<<low<<"\n";
    return 0;
}