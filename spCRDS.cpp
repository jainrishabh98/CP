#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m = 1e6 + 7;

int main ()
{   int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll p1 = ((n*(n-1))/2)%m;
        ll p2 = (n*(n+1))%m;
        cout<<(p1+p2)%m<<"\n";
    }
    return 0;
}