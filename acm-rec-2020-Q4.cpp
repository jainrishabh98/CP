#include <bits/stdc++.h>
using namespace std;
int bit[256][100001];
int m = 1e9 + 7;
int mod(int v)
{
    if (v >= m)
        v -= m;
    return v;
}
void update(int k, int p, int val)
{
    while (k < 100001)
    {
        bit[p][k] = mod(bit[p][k] + val);
        k += (k & (-k));
    }
}
int query(int k, int p)
{
    int s = 0;
    while (k > 0)
    {
        s = mod(s + bit[p][k]);
        k -= (k & (-k));
    }
    return s;
}
int main()
{
    int n, k, ans = 0,h,c,qq;
    scanf("%d%d",&n,&k);
    int b = (1 << k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&h,&c);
        c--;
        c = (1 << c);
        for (int msk = 0; msk < b; msk++)
        {
            qq = query(h - 1, msk);
            if (qq > 0)
            {
                update(h, (msk | c), qq);
            }
        }
        update(h, c, 1);
    }
    ans = query(100000,b-1);
    printf("%d",ans);
}