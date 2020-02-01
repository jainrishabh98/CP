#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, q;
    cin >> n >> m >> q;
    ll gc = __gcd(n, m);
    ll nn = n / gc;
    ll mm = m / gc;
    for (int i = 0; i < q; i++)
    {
        ll s1, s2, e1, e2;
        cin >> s1 >> s2 >> e1 >> e2;
        s2--;e2--;
        if (s1 == 1)
            s2 /= nn;
        else
            s2 /= mm;
        if (e1 == 1)
            e2 /= nn;
        else
            e2 /= mm;
        if (e2 == s2)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}