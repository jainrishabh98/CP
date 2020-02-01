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
        ll n;
        cin>>n;
        ll p = n;
        ll c=0;
        while(p!=0)
        {
            p /= 10;
            c++;
        }
        ll ans = 9*(c-1);
        for(int i=1;i<=9;i++)
        {
            ll num = 0;
            for(int j=1;j<=c;j++)
            {
                num = num*10 + i;
            }
            if(num <= n)
                ans++;
        }
        cout<<ans<<"\n";
    }
}