#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int j = 0, i = 0, st = 0, fl = 0;
    while (i < n)
    {
        while(b[i]!=a[0] && i < n)
        {
            i++;
        }
        if(i==n) break;
        st = i;
        while (b[i % n] == a[j] && j < n)
        {
            i++;
            j++;
        }
        if (j == n)
        {
            fl = 1;
            break;
        }
        j = 0;
        i = st+1;
    }
    if (fl == 0)
    {
        cout << -1;
    }
    else
    {
        cout << min(n-st,st);
    }
}