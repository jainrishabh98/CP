#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    if (x <= a)
    {
        a -= x;
        b += a;
        if (y <= b)
        {
            b -= y;
            c += b;
            if (z <= c)
            {
                cout << "YES";
            }
            else
            {
                cout << "NO";
            }
        }
        else
        {
            cout << "NO";
        }
    }
    else
    {
        cout << "NO";
    }
}