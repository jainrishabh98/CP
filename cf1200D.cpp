#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n + 1][n + 1];
    char x;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            if (x == 'B')
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }
    int mprer[n + 2][n + 2];
    int mprec[n + 2][n + 2];
    int cnt =0;
    memset(mprer,0,sizeof(mprer));
    memset(mprec,0,sizeof(mprec));
    for (int i = 1; i <= n; i++)
    {
        int fl1 = 0, fl2 = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 1)
            {
                fl1 = 1;
            }
            if (a[j][i] == 1)
            {
                fl2 = 1;
            }
        }
        
        if (fl1 == 0)
            cnt++;
        if (fl2 == 0)
            cnt++;
    }
    int aa[n + 1][n + 1];
    memset(aa, 0, sizeof(aa));
    for (int i = 1; i <= n; i++)
    {
        int l = n + 1, r = -1;
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 1)
            {
                l = min(l, j);
                r = max(r, j);
            }
        }
        if (r - l + 1 <= k && l!=n+1)
        {
            int diff = k - (r - l + 1);
            for (int j = l; j >= max(1, l - diff); j--)
                aa[i][j] = 1;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            mprer[i][j] = mprer[i + 1][j] + aa[i][j];
        }
    }
    memset(aa, 0, sizeof(aa));
    for (int i = 1; i <= n; i++)
    {
        int l = n + 1, r = -1;
        for (int j = 1; j <= n; j++)
        {
            if (a[j][i] == 1)
            {
                l = min(l, j);
                r = max(r, j);
            }
        }
        if (r - l + 1 <= k && l!=n+1)
        {
            int diff = k - (r - l + 1);
            for (int j = l; j >= max(1, l - diff); j--)
                aa[j][i] = 1;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            mprec[j][i] = mprec[j][i + 1] + aa[j][i];
        }
    }
    int ans = 0;
    for(int i=1;i<=n-k+1;i++)
    {
        for(int j=1;j<=n-k+1;j++)
        {
            int x = mprer[i][j] - mprer[i+k][j];
            int y = mprec[i][j] - mprec[i][j+k];
            ans = max(ans,x+y+cnt);
        }
    }
    cout<<ans;
}