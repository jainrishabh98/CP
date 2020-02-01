#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> m;
    while (m--)
    {
        ll n, t, a, b;
        cin >> n >> t >> a >> b;
        pair<ll, ll> p[n];
        ll cn[2] = {0};
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].second;
            cn[p[i].second]++;
        }
        for (int i = 0; i < n; i++)
            cin >> p[i].first;
        sort(p, p + n);
        int i = 0;
        ll ans = 0;
        ll pre = 0;
        while (i <= n)
        {
            ll tt;
            if (i < n)
                tt = p[i].first - 1;
            else
                tt = t;
            tt -= pre;
            if (tt >= 0)
            {
                ll temp = 0;
                ll aa = tt / a;
                temp = min(aa, cn[0]);
                if (aa > cn[0])
                {
                    tt -= a * cn[0];
                    temp += min(tt / b, cn[1]);
                }
                // cout<<temp<<" "<<pre<<" "<<i<<"\n";
                ans = max(ans, temp + i);
            }
            if (i == n)
                break;
            ll j = i;
            while (p[j].first == p[i].first && j < n)
            {
                if(p[j].second == 0)
                    pre += a;
                else
                    pre += b;
                cn[p[j].second]--;
                j++;
            }
            i = j;
        }
        cout << ans << "\n";
    }
}