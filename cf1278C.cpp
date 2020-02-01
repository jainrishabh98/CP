#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int l[n], r[n];
        int cn[2];
        cn[0] = cn[1] = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> l[i];
            l[i]--;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> r[i];
            r[i]--;
            cn[r[i]]++;
        }
        map<pair<int, int>, int> mp;
        int mn = min(cn[0], cn[1]);
        cn[0] -= mn;
        cn[1] -= mn;
        mp[{cn[0], cn[1]}] = 1;
        for (int i = 0; i < n; i++)
        {
            if (cn[r[i]] > 0)
                cn[r[i]]--;
            else
                cn[(r[i] ^ 1)]++;
            if (mp.find({cn[0], cn[1]}) == mp.end())
            {
                mp[{cn[0], cn[1]}] = i + 2;
            }
        }
        int ans = 2 * n;
        int cc[2];
        cc[0] = cc[1] = 0;
        if (mp.find({cc[1], cc[0]}) != mp.end())
        {
            ans = min(ans, n - 1 + mp[{cc[1], cc[0]}]);
        }
        for (int i = 0; i < n; i++)
        {
            if (cc[(l[i] ^ 1)] > 0)
                cc[(l[i] ^ 1)]--;
            else
                cc[l[i]]++;
            if (mp.find({cc[1], cc[0]}) != mp.end())
            {
                // cout<<i<<" "<<cc[0]<<" "<<cc[1]<<" "<<mp[{cc[1], cc[0]}]<<"\n";
                ans = min(ans, n - i - 2 + mp[{cc[1], cc[0]}]);
            }
        }
        cout << ans << "\n";
    }
}