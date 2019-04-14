#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        if(b*b - 4*a*c > 0)
            cout<<2<<"\n";
        else if(b*b - 4*a*c == 0)
            cout<<1<<"\n";
        else
            cout<<0<<"\n";
    }
}