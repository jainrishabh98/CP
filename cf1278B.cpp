#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll c = max(a+a,b+b);
        ll s = a+b;
        for(ll i=0;i<=1e5;i++)
        {
            ll pp = (i*(i+1))/2;
            if((s+pp)%2==0 && s+pp>= c)
            {
                cout<<i<<"\n";
                break;
            }
        }
    }
}