#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, d;
    cin >> n >> k >> d;
    int p = n / k;
    if (k >= n)
    {
        for (int j = 1; j <= d; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
        return 0;
    }
    if (d == 1 || p + n % k > k)
    {
        cout << "-1";
        return 0;
    }
    for (int j = 1; j <= d - 1; j++)
    {
        for (int i = 1; i <= k; i++)
        {
            for (int h = 1; h <= p; h++)
                cout << i << " ";
        }
        for (int h = p * k + 1; h <= n; h++)
        {
            cout << k << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i <= k; i++)
    {
        for (int h = 1; h <= p; h++)
            cout << h << " ";
    }
    for (int h = p * k + 1; h <= n; h++)
    {
        cout << p + (h - p * k ) << " ";
    }
    cout << "\n";
}