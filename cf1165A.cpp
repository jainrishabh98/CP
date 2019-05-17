#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, n;
    cin >> n >> x >> y;
    int a[n];
    char xx;
    for (int i = 0; i < n; i++)
    {
        cin >> xx;
        a[i] = xx - '0';
    }

    int cn = 0;
    int cnt = 0;
    for (int i = n - 1; i >= n - x; i--)
    {
        cn++;
        if (cn == y + 1)
        {
            // cout << cn << " " << y << " " << a[i] << "\n";
            if (a[i] != 1)
                cnt++;
        }
        else if (a[i] != 0)
            cnt++;
        // cout << i << " " << cnt << " ";
    }
    cout << cnt;
}