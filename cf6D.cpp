#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    int h[n];
    int mx = 15/a;
    mx++;
    int copy[n];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
       
    }
    int ans[n];
    int num[n];
    int hh[n];
    int ex1 = 0, ex2 = 0;
    for (int j = 0; j <= n - 1; j++)
    {
        num[j] = 0;
        ans[j] = 0;
        
    }
    while (h[0] >= 0)
    {
        h[0] -= b;
        h[1] -= a;
        h[2] -= b;
        ex1++;
    }
    while (h[n - 1] >= 0)
    {
        h[n - 1] -= b;
        h[n - 2] -= a;
        h[n - 3] -= b;
        ex2++;
    }
    for (int i = 0; i < n; i++)
    {
        copy[i] = h[i];
    }

    int mn = 10000;
    // int flag = 0;
    while (true)
    {
        int sum = 0, fl = 0;
        for (int j = 1; j < n - 1; j++)
        {
            copy[j] -= num[j] * a;
            copy[j - 1] -= num[j] * b;
            copy[j + 1] -= num[j] * b;
            sum += num[j];
        }
        for (int j = 0; j <= n - 1; j++)
        {
            if (copy[j] >= 0)
            {
                fl = 1;
            }
            copy[j] = h[j];
        }
        if (fl == 0 && sum < mn)
        {
            for (int j = 1; j < n - 1; j++)
            {
                ans[j] = num[j];
            }
            mn = sum;
        }
        int carry = 1, i = n - 2;
        while (carry != 0 && i >= 1)
        {
            num[i] += carry;
            carry = 0;
            if (num[i] > mx)
            {
                num[i] = 0;
                carry = 1;
            }
            i--;
        }
        if (i == 0 && carry == 1)
        {
            break;
        }
    }
    mn += ex1 + ex2;
    ans[1] += ex1;
    ans[n - 2] += ex2;
    cout << mn << "\n";
    for (int j = 1; j < n - 1; j++)
    {
        while (ans[j] > 0)
        {
            cout << j + 1 << " ";
            ans[j]--;
        }
    }
}