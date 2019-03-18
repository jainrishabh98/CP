#include <bits/stdc++.h>
using namespace std;
int pf[10000001];
int cnt[10000001];
long long int m = 1e7;
void sieve()
{
    for (int i = 1; i <= m; i++)
    {
        pf[i] = i;
    }
    for (int i = 2; i * i <= m; i++)
    {
        if (pf[i] == i)
        {
            for (int j = i * i; j <= m; j += i)
            {
                if (pf[j] == j)
                    pf[j] = i;
            }
        }
    }
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long int n, q, l, r;
    cin >> n;
    int y;
    int prev = 1;
    sieve();
    for (int i = 0; i < n; i++)
    {
        cin >> y;
        prev = 1;
        while (y != 1)
        {
            if (pf[y] != prev)
            {
                cnt[pf[y]]++;
                prev = pf[y];
            }
            y /= pf[y];
        }
    }
    for (int i = 2; i <= m; i++)
    {
        cnt[i] += cnt[i - 1];
    }
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        if(r>m) r = m;
        if(l>m) l = m;
        cout << cnt[r] - cnt[l - 1] << "\n";
    }
}