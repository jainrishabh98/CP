#include <bits/stdc++.h>
using namespace std;
struct st
{
    double a, b;
};
int main()
{
    int t;
    cin >> t;
    for (int l = 1; l <= t; l++)
    {
        int n;
        cin >> n;
        st s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i].a >> s[i].b;
        }
        double mx = 1e11, mn = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i].a > s[i - 1].a)
            {
                mn = max(mn, (s[i - 1].b - s[i].b) / (s[i].a - s[i - 1].a));
            }
            else if (s[i].a < s[i - 1].a)
            {
                mx = min(mx, (s[i - 1].b - s[i].b) / (s[i - 1].a - s[i].a));
            }
        }
        if (mn >= mx)
            cout << "Case #" << l << ": IMPOSSIBLE\n";
        else
        {
            long long int low = 1, high = 1000000000, mid, x, y, ll, hh, mm;
            while (low <= high)
            {
                mid = (low + high) / 2;
                long long int yy = mx * mid;
                if(yy == floor(mx * mid)) yy--;
                long long int xx = mn * mid;
                if(xx!=ceil(mn * mid)) xx++;
                if (yy >= xx)
                {
                    y = mid;
                    x = xx;
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            cout << "Case #" << l << ": "<<x<<" "<<y<<"\n";
        }
    }
}