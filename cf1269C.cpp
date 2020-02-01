#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n], b[n];
    char x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a[i] = x - '0';
    }
    for (int i = 0; i < k; i++)
        b[i] = a[i];
    for (int i = k; i < n; i++)
        b[i] = b[i - k];
    int fl = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            fl = 1;
            break;
        }
        else if (a[i] < b[i])
        {
            fl = 2;
            break;
        }
    }
    if (fl == 1)
    {
        int i = k - 1;
        int cy = 1;
        while (cy == 1 && i >= 0)
        {
            b[i]++;
            cy = 0;
            if (b[i] == 10)
            {
                cy = 1;
                b[i] = 0;
            }
            i--;
        }
    }
    for (int i = k; i < n; i++)
        b[i] = b[i - k];
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << b[i];
    }
}