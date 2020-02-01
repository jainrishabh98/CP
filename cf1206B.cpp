#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll cost = 0;
    ll cnt = 0, cn = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            cost += (-1 - a[i]);
            cnt++;
        }
        else if (a[i] > 0)
        {
            cost += (a[i] - 1);
            cn++;
        }
    }
    cn = n - cnt - cn;
    if (cn > 0)
    {
        cost += cn;
    }
    else if (cnt % 2 != 0)
    {
        cost += 2;
    }
    cout << cost;
}