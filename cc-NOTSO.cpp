#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mx = 1000000000000000000;
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
        ll n;
        cin >> n;
        ll a[n];
        cin >> a[0];
        int c = 1;
        for (int i = 1; i < n; i++)
        {
            if (i % 2 == 0)
            {
                // a[i] = 2 * a[i - 1] + a[i - 2];
                if (a[i - 1] > (mx - a[i - 2]) / 2)
                    break;
                a[i] = 2 * a[i - 1] + a[i - 2];
                ll r = a[i] % 4;
                if (r > 0)
                {
                    a[i] += 4 - r;
                }
            }
            else
            {
                if (a[i - 1] > mx / 3)
                    break;
                a[i] = 3 * a[i - 1];
                ll r = a[i] % 5;
                if (r > 0)
                {
                    a[i] += 5 - r;
                }
            }
            c++;
        }
        // cout<<c<<"\n";
        // for(int i=0;i<c;i++)
        // {
        //     cout<<a[i]<<" ";
        // }
        // cout<<"\n";
        ll q, s;
        cin >> q;
        while (q--)
        {
            cin >> s;
            int fl = 0;
            for (int i = c - 1; i >= 0; i--)
            {
                if (s >= a[i])
                {
                    s -= a[i];
                    if (s == 0)
                    {
                        fl = 1;
                        break;
                    }
                }
            }
            if (fl == 0)
                cout << "NO\n";
            else
            {
                cout << "YES\n";
            }
        }
    }
}