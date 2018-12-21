#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll f[7];
        f[1] = 1,f[2] = 3,f[3] =2,f[4] = -1,f[5] = -3,f[6] = -2;
        ll ans = 0;ll temp = (n+5)%6 + 1;
        for (int i=1;i<=temp;i++)
        {
            ans += f[i];
        } 
        cout<<ans<<"\n";
    }
    return 0;
}