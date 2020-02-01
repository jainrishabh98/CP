#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans = 0;
        for(ll i=1;i<=n;i++)
        {
            ll rem = n-i;
            if(i <= n/3)
            {
                if(rem%2==0)
                    rem--;
                rem--;
                ans += max((ll)0,rem);

            }
            else
            {
                if(rem > i)
                {
                    rem -= 2;
                }
                rem--;
                ans += max((ll)0,rem);
            }
        }
        cout<<ans<<"\n";
    }
}