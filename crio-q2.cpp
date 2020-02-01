#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    string a, b;
    cin >> n >> a >> b >> k;
    ll s[n + 1];
    s[1] = a.length();
    s[2] = b.length();
    for (int i = 3; i <= n; i++)
    {
        s[i] = s[i - 2] + 2 * s[i - 1];
    }
    if (s[n] < k)
    {
        cout << -1;
        return 0;
    }
    //k--;
    char ans;
    for (int i = n; i >= 3;)
    {
        if (s[i - 2] < k)
        {
            k -= s[i - 2];
            if (k > s[i - 1])
                k -= s[i - 1];
            i--;
            if (i == 2)
            {
                ans = b[k - 1];
                break;
            }
        }
        else
        {
            i -= 2;
            if (i == 2)
            {
                ans = b[k - 1];
                break;
            }
            else if (i == 1)
            {
                ans = a[k - 1];
                break;
            }
        }
    }
    cout << ans;
}