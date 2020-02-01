#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int p[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        int g = 0, s = 0, b = 0;
        int i = 0;
        n = n / 2;
        while (p[i] == p[0] && i < n)
        {
            g++;
            i++;
        }
        while (g >= s && i < n)
        {
            int j = i;
            int c = 0;
            while (p[i] == p[j] && i < n)
            {
                c++;
                i++;
            }
            if (i < n || p[i]!=p[j])
                s += c;
        }
        if (g >= s)
        {
            cout << 0 << " " << 0 << " " << 0 << "\n";
            continue;
        }
        while (g >= b && i < n)
        {
            int j = i;
            int c = 0;
            while (p[i] == p[j] && i < n)
            {
                c++;
                i++;
            }
            if (i < n || p[i]!=p[j])
                b += c;
        }
        if (g >= b)
        {
            cout << 0 << " " << 0 << " " << 0 << "\n";
            continue;
        }
        while (i < n)
        {
            int j = i;
            int c = 0;
            while (p[i] == p[j] && i < n)
            {
                c++;
                i++;
            }
            if (i < n || p[i]!=p[j])
                b += c;
        }
        cout << g << " " << s << " " << b << "\n";
    }
}