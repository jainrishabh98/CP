#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int q[n], s[n], t[n], tt[n];
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
        q[i]--;
    }
    int fl=0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        s[i]--;
        if(s[i]!=i)
            fl=1;
    }
    if(fl==0)
    {
        cout<<"NO";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        t[i] = i;
    }
    int i = 1;
    int flag = 0;
    for (; i <= k; i++)
    {
        flag = 0;
        for (int j = 0; j < n; j++)
        {
            tt[j] = t[q[j]];
            if (tt[j] != s[j])
                flag = 1;
        }
        if (flag == 0)
            break;
        for (int j = 0; j < n; j++)
            t[j] = tt[j];
    }
    for (int j = 0; j < n; j++)
        t[j] = j;
    int p = i;
    i = 1;
    int flag3 = 0;
    for (; i <= k; i++)
    {
        flag3 = 0;
        for (int j = 0; j < n; j++)
        {
            tt[q[j]] = t[j];
            if (tt[q[j]] != s[q[j]])
                flag3 = 1;
        }
        if (flag3 == 0)
            break;
        for (int j = 0; j < n; j++)
            t[j] = tt[j];
    }
    if (flag3 == 0 && flag == 0 && i == 1 && p == 1 && k != 1)
    {
        cout << "NO";
        return 0;
    }
    if ((flag3 == 0 && (k - i) % 2 == 0) || (flag == 0 && (k - p) % 2 == 0))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}