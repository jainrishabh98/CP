#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int l = 1; l <= t; l++)
    {
        int r, c;
        cin >> r >> c;
        int m[r][c];
        char x;
        int visr[r] = {0};
        int visc[c] = {0};
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> x;
                if (x == '.')
                    m[i][j] = 0;
                else
                {
                    m[i][j] = 1;
                    visr[i] = 1;
                    visc[j] = 1;
                }
            }
        }
        if (r == 1 && c == 1)
        {
            if (m[0][0] == 1)
                cout << "Case #" << l << ": " << 0 << "\n";
            else
                cout << "Case #" << l << ": " << 2 << "\n";
            continue;
        }
        int cr = 0, cc = 0;
        int p1 = 0, p2 = 0, ans1 = 0, ans2 = 0;
        for (int i = 0; i < r; i++)
        {
            if (visr[i] == 0)
            {
                cr++;
                if (i == 0 || i == r - 1)
                    p1++;
            }
        }
        for (int j = 0; j < c; j++)
        {
            if (visc[j] == 0)
            {
                cc++;
                if (j == 0 || j == c - 1)
                    p2++;
            }
        }
        ans1 = cc * (cr - p1 + 1) + cr;
        ans2 = cr * (cc - p2 + 1) + cc;
        int ans = max(ans1, ans2);
        if (ans % 2 == 0)
        {
            cout << "Case #" << l << ": 0\n";
        }
        else
        {
            int y = cc * r + cr * c;
            cout << "Case #" << l << ": " << y << "\n";
        }
    }
}