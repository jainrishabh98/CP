#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        if(z>x && z>y)
            cout<<"NO\n";
        else if(z==x || z==y)
            cout<<"YES\n";
        else
        {
            ll g = __gcd(x,y);
            if(z%g==0)
            {
                cout<<"YES\n";
            }
            else 
                cout<<"NO\n";
        }

    }
    return 0;
}