#include <bits/stdc++.h>
using namespace std;
int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string a[n];
    char x;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int right[m][n];
    // right[i][j] stores the number of consecutive 1's to the right of (j,i) and starting at position (j,i) (including it)
    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (a[i][j] == '0')
                right[j][i] = 0;
            else if (j == m - 1)
                right[j][i] = 1;
            else
                right[j][i] = right[j + 1][i] + 1;
        }
    }
    int answer = 0;
    int cnt[m+1];
    for (int j = 0; j < m; j++)
    {
        memset(cnt, 0, sizeof(cnt));
        vector <int> output(n);
        for (int i = 0; i < n; i++)
        {
            cnt[right[j][i]]++;
        }
        for (int i = 1; i <= m; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            output[cnt[right[j][i]] - 1] = right[j][i];
            cnt[right[j][i]]--;
        }

        for (int i = 0; i < n; i++)
            right[j][i] = output[i]; 
        for (int i = 0; i < n; i++)
        {
             if (right[j][i]*(n-i) > answer) answer = right[j][i]*(n-i);
        }
        
        
    }
    cout<<answer<<"\n";
    return 0;
}