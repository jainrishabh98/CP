#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    long long int a[n],b[n];
    long long int m = 998244353;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] *= (n-i)*(i+1);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(a, a + n);
    reverse(a,a+n);
    sort(b, b + n);
    long long int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (((a[i]%m) * b[i]) % m);
        ans = ans%m;
    }
    cout << ans;
}