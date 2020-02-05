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
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ind = -1, fl = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < i)
            {
                ind = i;
                break;
            }
        }
        if (ind != -1)
        {
            for (int i = ind; i < n; i++)
            {
                if (a[i] < n - 1 - i)
                {
                    fl = 1;
                    break;
                }
            }
            if(a[ind] == a[ind-1] && a[ind-1] == ind - 1 && a[ind] == n - 1 - ind)
                fl=1;
        }
        if (fl == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}