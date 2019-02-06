#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    if (n == 1)
        cout << "-1";
    else if (n == 2)
    {
        int d = a[1] - a[0];
        if(d==0)
        {
            cout<<"1\n"<<a[0];
        }
        else if (d % 2 == 0)
        {
            cout << "3\n"
                 << a[0] - d << " " << a[0] + d / 2 << " " << a[1]+d;
        }
        else
        {
            cout << "2\n"
                 << a[0] - d << " " << a[1] + d;
        }
    }
    else
    {
        set<int> d;
        for (int i = 1; i < n; i++)
        {
            d.insert(a[i] - a[i - 1]);
        }
        if (d.size() > 2)
        {
            cout << "0";
        }
        else if (d.size() == 2)
        {
            // cout << "1\n";
            auto tmp = d.begin();
            int x = *tmp;
            tmp++;
            int y = *tmp;
            if (y != 2 * x)
            {
                cout << "0";
                return 0;
            }
            int fl = 0;
            int ans = 0;
            for (int i = 1; i < n; i++)
            {
                if (a[i] - a[i - 1] == x)
                    continue;
                else if (a[i] - a[i - 1] == y && fl == 0)
                {
                    fl = 1;
                    ans = a[i] - x;
                }
                else if (a[i] - a[i - 1] == y && fl == 1)
                {
                    cout << "0";
                    return 0;
                }
            }
            cout << "1\n" << ans;
        }
        else
        {
            if(*d.begin()!=0)
            {
            cout << "2\n";
            cout << a[0] - (*d.begin()) << " " << a[n - 1] + (*d.begin());
            }
            else
            {
                cout<<"1\n"<<a[0];
            }
        }
    }
}