#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n][n];
    char x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            if (x == '.')
                a[i][j] = 0;
            else
                a[i][j] = 1;
        }
    }
    int flag = 0;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (a[i][j] == 0)
            {
                if (a[i - 1][j] == 0 && a[i + 1][j] == 0 && a[i][j - 1] == 0 && a[i][j + 1] == 0)
                {
                    a[i - 1][j] = a[i + 1][j] = a[i][j - 1] = a[i][j + 1] = a[i][j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                flag = 1;
                break;
            }
        }
    }
    if(flag==1)
        cout<<"NO";
    else
        cout<<"YES";
}