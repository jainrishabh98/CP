#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, h, y1, y2, l;
        cin >> n >> h >> y1 >> y2 >> l;
        int ans = 0, t, x, fl = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> t >> x;
            if (fl == 0)
            {
                if (t == 1)
                {
                    if (h - y1 <= x)
                    {
                        ans++;
                    }
                    else
                    {
                        if (l > 1)
                        {
                            ans++;
                            l--;
                        }
                        else
                        {
                            fl = 1;
                        }
                    }
                }
                else
                {
                    if (y2 >= x)
                    {
                        ans++;
                    }
                    else
                    {
                        if (l > 1)
                        {
                            ans++;
                            l--;
                        }
                        else
                        {
                            fl = 1;
                        }
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}