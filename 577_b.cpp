#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    unordered_map<int, int> s;
    set<int> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] = arr[i] % m;
        s[arr[i]]++;
    }
    if(n>m){cout<<"YES";return 0;}
    vector<int> v;
    for (auto i : s)
    {
        int g = 0;
        int y = i.second;
        while (y > 0)
        {
            g += i.first;
            k.insert(g);
            y--;
            // cout<<"";
        }
    }
    for (auto i : k)
        v.push_back(i);
    n = v.size();
    bool dp[n + 1][m + 1];
    

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
        dp[i][v[i]] = 1, dp[i][0] = 1;
    dp[0][v[0]]=1;
    for (int i = 0; i < n; i++)
    {
        // cout<<v[i]<<" ";
        for (int j = 1; j <= m; j++)
        {
            if ((i!=0 )&& (j >= v[i]))
                dp[i][j] = dp[i - 1][(j - v[i])] || dp[i - 1][j];
            else if(i!=0)
                dp[i][j] = dp[i - 1][j];
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }
    if( dp[n-1][m])  cout<<"YES"; else cout<<"NO";
}