#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    if (n * m == 2)
    {
        cout << 0 << "\n";
        cout << 1 << " " << 1 << "\n";
        cout << n << " " << m << "\n";
        cout << 1 << " " << 1 << "\n";
        return 0;
    }
    if (n % 2 != 0 && m % 2 != 0 || n == 1 || m == 1)
    {
        cout << 1 << "\n"
             << n << " " << m << " " << 1 << " " << 1 << "\n";
        for (int i = 1; i <= m; i++)
        {
            if (i % 2 != 0)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << j << " " << i << "\n";
                }
            }
            else
            {
                for (int j = n; j >= 1; j--)
                {
                    cout << j << " " << i << "\n";
                }
            }
        }
        cout << 1 << " " << 1 << "\n";
    }
    else
    {
        cout << 0 << "\n"
             << 1 << " " << 1 << "\n";
        int flag = 0;
        if (m % 2 != 0)
        {
            flag = 1;
            int c = n;
            n = m;
            m = c;
        }
        for (int i = 1; i <= m; i++)
        {
            if (i % 2 != 0)
            {
                for (int j = 2; j <= n; j++)
                {
                    (flag == 0) ? cout << j << " " << i << "\n" : cout << i << " " << j << "\n";
                }
            }
            else
            {
                for (int j = n; j >= 2; j--)
                {
                    (flag == 0) ? cout << j << " " << i << "\n" : cout << i << " " << j << "\n";
                }
            }
        }
        for (int i = m; i >= 1; i--)
        {
            (flag == 0) ? cout << 1 << " " << i << "\n" : cout << i << " " << 1 << "\n";
        }
    }
}