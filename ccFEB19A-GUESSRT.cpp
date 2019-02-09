#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;
ll n,m,k,p,ans,inv,a,b,c;
ll fp(ll x,ll y)
{
    if(y==0)    return 1;
    else if(y==1)    return x;
    else if(y%2==0) return (fp(x,y/2) * fp(x,y/2))%mod;
    else return (((fp(x,y/2) * fp(x,y/2))%mod)*x)%mod;
}
int main ()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin>>t;
    cout<<"h ";
    while(t--)
    {   
        cout<<"h ";
        cin>>n>>k>>m;
        cout<<"h ";
        p = (m+1)/2;
        cout<<"h ";
        c = fp(n-1,p);
        cout<<"h ";
        b = fp(n,p);
        cout<<"h ";
        a = (b-c+mod)%mod;
        cout<<"h ";
        inv = fp(b,mod-2);
        cout<<"h ";
        ans = (a*inv)%mod;
        cout<<"h ";
        if(m%2==0)
        {
            b = (b*(n+k))%mod;
            inv = fp(b,mod-2);
            ans = (ans + (c*inv)%mod)%mod;
        }
        cout<<ans<<"\n";
    }
}