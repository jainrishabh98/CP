#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    ll a[t];
    for(int i=0;i<t;i++)
        cin>>a[i];
    for(int i=0;i<t;i++)
    {
        ll x = a[i]%14;
        if(x>=1 && x <= 6 && a[i]>14)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
        
    }
}