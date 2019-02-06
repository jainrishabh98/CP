#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll tree[5001][5001];
long long int m = 1e9 + 7;
int n, a, b, t;
int mod(long long int num)
{
    if (num >= m)
    {
        num -= m;
    }
    return num;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b >> t;
    ll temp,tm;
    if (a > b)
    {
        tree[0][b+1] = 1;
        for (int i = b + 2; i <= n; i++)
        { tree[0][i] = mod(1 + tree[0][i-1]); }
        for (int k = 1; k <= t; k++)
        {
            for (int i = b + 1; i <= n; i++)
            {
                temp = tree[k-1][min(i+i-b-1,n)];
                tm = tree[k-1][i] - tree[k-1][i-1] + m;
                tm = mod(tm);
                temp = mod(temp - tm + m);
                tree[k][i] = temp;
            }
            for (int i = b + 2; i <= n; i++)
            { tree[k][i] = mod(tree[k][i] + tree[k][i-1]); }
        }
        cout<<mod(tree[t][a] - tree[t][a-1] + m);
    }
    else
    {
        tree[0][1] = 1;
        for (int i = 2; i < b; i++)
        { tree[0][i] = mod(1 + tree[0][i-1]); }
        for (int k = 1; k <= t; k++)
        {
            for (int i = b - 1; i >= 1; i--)
            {
                temp = mod(tree[k-1][b-1] - tree[k-1][max(2*i-b,0)] + m);
                tm = tree[k-1][i] - tree[k-1][i-1] + m;
                tm = mod(tm);
                temp = mod(temp - tm + m);
                tree[k][i] = temp;
            }
            for (int i = 2; i < b; i++)
            { tree[k][i] = mod(tree[k][i] + tree[k][i-1]); }
        }
        cout<<mod(tree[t][a] - tree[t][a-1] + m);
    }
}
