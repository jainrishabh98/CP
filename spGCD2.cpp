#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;  
ll gcd(ll a, ll b) 
{ 
    if (!a) 
       return b; 
    return gcd(b%a,a); 
}
int main ()
{   int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        string b;
        cin>>b;
        ll mod = 0; 
        if(a!=0)
        {
        for (int i=0; i<b.length(); i++) 
            mod = (mod*10 + b[i] - '0')%a;
        
        ll ans = gcd(a,mod);
        cout<<ans<<"\n";
        }
        else
            cout<<b<<"\n";

    }
    return 0;
}