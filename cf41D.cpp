#include <bits/stdc++.h>
using namespace std;
int dp[105][105][11];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    char x;
    int a[n + 1][m + 1];
    k++;
    memset(dp,-1,sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> x;
            a[i][j] = x - '0';
            if (i == n)
            {
                dp[i][j][a[i][j] % k] = a[i][j];
            }
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int kk = 0; kk < k; kk++)
            {
                int t1 = 0, t2 = 0;
                if (dp[i + 1][j - 1][kk] != -1)
                {
                    t1 = dp[i + 1][j - 1][kk] + a[i][j];
                    dp[i][j][t1 % k] = max(dp[i][j][t1 % k], t1);
                }
                if (dp[i + 1][j + 1][kk] != -1)
                {
                    t2 = dp[i + 1][j + 1][kk] + a[i][j];
                    dp[i][j][t2 % k] = max(dp[i][j][t2 % k], t2);
                }
            }
        }
    }
    int c,max=-1;
    for(int i=1;i<=m;i++)
    {
        if(dp[1][i][0] > max)
        {
            max = dp[1][i][0];
            c = i;
        }
    }
    cout<<max<<"\n";
    if(max==-1)
    {
        return 0;
    }
    vector <char> ans;
    int i = 1;
    int val = max;
    while(i!=n)
    {
        val -= a[i][c];
        if(dp[i+1][c-1][val%k]==val)
        {
            ans.push_back('R');
            c--;
        }
        else if(dp[i+1][c+1][val%k]==val)
        {
            ans.push_back('L');
            c++;
        }
        i++;
    }
    cout<<c<<"\n";
    for(int j=ans.size()-1;j>=0;j--)
    {
        cout<<ans[j];
    }
}