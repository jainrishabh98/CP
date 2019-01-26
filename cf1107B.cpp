#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll n,k,x;
    cin>>n;
    while(n--)
    {
        cin>>k>>x;
        cout<<(x+(k-1)*9)<<"\n";
    }
}