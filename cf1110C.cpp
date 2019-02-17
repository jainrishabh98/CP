#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    int a[q], b = 1;
    for (int i = 0; i < q; i++)
        cin >> a[i];
    int p = 1;
    int ans[26];
    ans[1] = 1;
    for (int i = 2; i <= 25; i++)
    {
        p = p * 2 + 1;
        int g = p / 2;
        while ((p - g) % g != 0)
            g -= 2;
        ans[i] = g;
    }
    for (int i = 0; i < q; i++)
    {
        int t = a[i], cnt = 0;
        while (t != 0)
        {
            t /= 2;
            cnt++;
        }
        t = a[i];
        if ((t & (t + 1)) == 0)
        {
            cout << ans[cnt] << "\n";
        }
        else
        {

            cout << ((ll)pow(2, cnt)) - 1 << "\n";
        }
    }
}