#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, b, a;
    cin >> n >> b >> a;
    int s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int i = 0;
    int a2 = a;
    while ((a != 0 || b != 0) && i < n)
    {
        if (s[i] == 1)
        {
            if (b == 0 || a2 == a)
                a--;

            else
            {
                a++;
                b--;
            }
        }
        else
        {
            if (a != 0)
                a--;
            else if (b != 0)
                b--;
        }
        i++;
    }
    cout << i;
}