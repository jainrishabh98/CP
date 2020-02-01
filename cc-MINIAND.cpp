#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,l,r,q;
        cin>>n;
        ll a[n+1];
        a[0] = 0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i] %= 2;
            a[i] += a[i-1];
        }
        cin>>q;
        while(q--)
        {
            cin>>l>>r;
            if(a[r]-a[l-1] == r - l + 1)
                cout<<"ODD\n";
            else
                cout<<"EVEN\n";
        }
    }
}