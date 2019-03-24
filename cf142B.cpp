#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    if (m == 1 || n == 1)
    {
        cout << max(n, m);
    }
    else if (m == 2 || n==2)
    {   
        n = max(n,m);
        int ans1 = 4 * (n / 4);
        if (n % 4 >= 2)
        {
            ans1 += 4;
        }
        else if (n % 4 == 1)
        {
            ans1 += 2;
        }
        cout << ans1;
    }
    else
    {
        int ans1 = (m / 2) * n;
        if (m % 2 == 1)
            ans1 += ceil(n / 2.0);
        cout << ans1;
    }
}