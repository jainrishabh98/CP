#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
unordered_map <ll,ll> ump;
ll fun(ll n)
{
    if(n==0)
        return 0;
    if(ump.find(n)!=ump.end())
        return ump[n];
    ump[n] = max(n,fun(n/2)+fun(n/3)+fun(n/4));
    return ump[n];
}
int main ()
{
    ll waste = fun(1000000000);
    ll n;
    while(cin>>n)
    {
        cout<<fun(n)<<"\n";
    }
}