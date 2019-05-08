#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a, c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a % 2 == 0)
            c1++;
        else
            c2++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        if (a % 2 == 0)
            c3++;
        else
            c4++;
    }
    cout<<min(c1,c4) + min(c3,c2);
}