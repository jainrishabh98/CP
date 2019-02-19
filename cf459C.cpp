#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int ans[1001][1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d, k;
    cin >> n >> k >> d;
    ll temp = 1;
    bool flag = false;
    for (int i = 0; i < d; i ++)
    {
        temp *= k;
        if (temp >= n)
        {
            flag = true;
            break;
        }
    }

    if (!flag) 
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i < n; i ++) 
    {
        for (int j = 0; j < d; j ++) ans[i][j] = ans[i - 1][j];
        for (int j = d - 1; j >= 0; j --)
        {
            ans[i][j] = (ans[i][j] + 1) % k;
            if (ans[i][j]) break;
        }
    }

    for (int i = 0; i < d; i ++, cout << endl)
        for (int j = 0; j < n; j ++)
            cout << ans[j][i] + 1 << ' ';
    
}