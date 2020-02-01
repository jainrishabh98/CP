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
    cin >> t;
    while (t--)
    {
        ll n, c, x;
        cin >> n >> c;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            c -= x;
        }
        if (c >= 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}