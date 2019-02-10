#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
map<ll, ll> cnt;
int main()
{
    ll n, b;
    cin >> n >> b;
    while (b % 2 == 0)
    {
        if (cnt.find(2) == cnt.end())
        {
            cnt[2] = 1;
        }
        else
            cnt[2] = cnt[2] + 1;
        b = b / 2;
    }
    for (ll i = 3; i <= sqrt(b); i = i + 2)
    {
        while (b % i == 0)
        {
            if (cnt.find(i) == cnt.end())
            {
                cnt[i] = 1;
            }
            else
                cnt[i] = cnt[i] + 1;
            b = b / i;
        }
    }
    if (b > 2)
    {
        if (cnt.find(b) == cnt.end())
        {
            cnt[b] = 1;
        }
        else
            cnt[b] = cnt[b] + 1;
    }
    ull ans = 1e18;
    for (auto i:cnt)
    {
            ull num = 0;
            long long int j = i.first;
            while (j <= n )
            {
                num += (n / j);
                if(n/j < i.first)
                    break;
                j *= i.first;
            }
            ans = min(ans, num / i.second);
    }
    cout << ans;
}