#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll d = abs(a - b);
        ll ans = 0;
        ans += d/5;
        d = d%5;
        ans += d/2;
        d = d%2;
        ans += d;
        cout<<ans<<"\n";
    }
}