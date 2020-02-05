#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll s;
        cin>>s;
        ll ans = 0;
        while(s >= 10)
        {
            ll p = s - s%10;
            s = s%10 + p/10;
            ans += p; 
        }
        ans += s;
        cout<<ans<<"\n";

    }
}