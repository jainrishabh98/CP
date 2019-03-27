#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int m, k, x;
    cin >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> x;
        mp[x] = 1;
    }
    int n;
    cin >> n;
    string s[n];
    int d[n] = {0};
    int cnt[n] = {0};
    int c[n] = {0};
    int mnsure[n] = {0};
    int mxsure[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        cin >> d[i];
        for (int j = 1; j <= d[i]; j++)
        {
            cin >> x;
            if (x == 0)
            {
                c[i]++;
            }
            else if (mp.find(x) != mp.end())
            {
                cnt[i]++;
            }
        }
        int t1 = d[i] - cnt[i] - c[i];
        int t2 = m - k - t1;
        int t3 = k - cnt[i];
        mnsure[i] = max(0, c[i] - t2) + cnt[i];
        mxsure[i] = min(c[i], t3) + cnt[i];
        
    }
    int mn = *max_element(mnsure, mnsure + n);
    int mx = *max_element(mxsure, mxsure + n);
    for (int i = 0; i < n; i++)
    {   
        // cout<<mnsure[i]<<" "<<mxsure[i]<<" ";
        if (mxsure[i] < mn)
        {
            cout << 1 << "\n";
            continue;
        }
        int temp = 0;
        for(int j=0;j<n;j++)
        {
            if(j==i)
                continue;
            temp = max(temp,mxsure[j]);
        }
        if(mnsure[i] >= temp)
            cout << 0 << "\n";
        else
            cout << 2 << "\n";
    }
}