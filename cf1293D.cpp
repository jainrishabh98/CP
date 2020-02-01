#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll x0, y0, ax, ay, bx, by, xs, ys, t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
    vector<ll> vx, vy;
    vx.push_back(x0);
    vy.push_back(y0);
    ll x = x0, y = y0;
    int ans = 0;
    while ((x <= 1e17/ax) && (y <= 1e17/ay))
    {
        x = ax * x + bx;
        y = ay * y + by;
        vx.push_back(x);
        vy.push_back(y);
    }
    int n = vx.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ll dist = abs(vx[i] - xs) + abs(vy[i] - ys) + abs(vx[i] - vx[j]) + abs(vy[i] - vy[j]);
            // cout<<i<<" "<<j<<" "<<dist<<"\n";
            if (dist <= t)
                ans = max(ans,abs(j-i)+1);
        }
    }
    cout << ans;
}