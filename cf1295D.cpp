#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll phi(ll n)
{
    double result = n;
    for (ll p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result *= (1.0 - (1.0 / (float)p));
        }
    }
    if (n > 1)
        result *= (1.0 - (1.0 / (float)n));
 
    return (ll)result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, m;
        cin >> a >> m;
        ll gc = __gcd(a, m);
        cout<<phi(m/gc)<<"\n";
    }
}