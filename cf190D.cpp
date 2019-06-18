#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int i = 0, j = 0;long long ans = 0;
    map<int, int> mp;
    while (i < n && j < n)
    {
        while (j < n)
        {
            if (mp.find(a[j]) == mp.end())
            {
                mp[a[j]] = 1;
            }
            else
            {
                mp[a[j]]++;
            }
            if (mp[a[j]] == k)
            {
                break;
            }
            j++;
        }
        if (j == n)
            break;
        while (mp[a[j]] == k)
        {
            ans += n - j;
            mp[a[i]]--;
            i++;
        }
        j++;
    }
    cout<<ans;
}