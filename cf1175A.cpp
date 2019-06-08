#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, k, ans = 0;
        cin >> n >> k;
        ans += n % k;
        n -= n % k;
        while (n != 0)
        {
            n /= k;
            ans++;
            ans += n % k;
            n -= n % k;
        }
        cout<<ans<<"\n";
    }
}