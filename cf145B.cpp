#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c > a || c > b || d > a || d > b || (d < c && d != c - 1) || (c < d && c != d - 1) || (c==d && (a<=c && b<=d)))
    {
        cout << -1;
        return 0;
    }
    string ans = "";
    if (c >d || (c==d && a>c))
    {
        a -= c;
        b -= c;
        while (a--)
        {
            ans.append("4");
        }
        a++;
        if (d == c)
        {
            ans.pop_back();
            a++;
        }
        while (c--)
        {
            ans.append("47");
        }
        while (b > 0)
        {
            ans.append("7");
            b--;
        }
        if (a == 1)
        {
            ans.append("4");
            a--;
        }
        cout << ans;
    }
    else
    {
        a -= d;
        b -= d;
        while (b--)
        {
            ans.append("7");
        }
        b++;
        if (d == c)
        {
            ans.pop_back();
            b++;
        }
        while (d--)
        {
            ans.append("74");
        }
        while (a > 0)
        {
            ans.append("4");
            a--;
        }
        if (b == 1)
        {
            ans.append("7");
            b--;
        }
        cout << ans;
    }
}