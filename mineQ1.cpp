#include <bits/stdc++.h>
using namespace std;
int mp[1000005];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n ;
        k = n-1;
        int a[n];
        memset(mp,0,sizeof(mp));
        int cnt[n + 1] = {0};
        int cn = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (mp[a[i]] != 0)
                cnt[mp[a[i]]]--;
            else
                cn++;
            mp[a[i]]++;
            cnt[mp[a[i]]]++;
        }
        int left = 0, right = n;
        for (int i = 1; i <= n; i++)
        {
            right -= (cnt[i] * i);
            left += cnt[i];
            int temp = (right - (cn - left) * i) + (n - (cnt[i] * i) - right);
            if (temp <= k)
            {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}