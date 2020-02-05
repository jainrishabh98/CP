#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
vector<vector<ll>> a, b, id;
vector<vector<ll>> mat_mul(vector<vector<ll>> x, vector<vector<ll>> y)
{
    vector<vector<ll>> temp(x.size(), vector<ll>(y[0].size(), 0));
    for (int i = 0; i < x.size(); i++)
        for (int j = 0; j < y[0].size(); j++)
            for (int k = 0; k < y.size(); k++)
                (temp[i][j] += (x[i][k] * y[k][j]) % mod) %= mod;
    return temp;
}
vector<vector<ll>> mat_expo(vector<vector<ll>> x, ll p)
{
    if (p == 0)
        return id;
    if (p == 1)
        return x;
    if(p % 2 == 0)
		return mat_expo(mat_mul(x, x), p / 2);
	return mat_mul(x, mat_expo(mat_mul(x, x), p / 2));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int s = 4;
    id = vector<vector<ll>>(s, vector<ll>(s, 0));
    for (ll i = 0; i < s; i++)
        id[i][i] = 1;
    // vector<vector<ll>> a(s, vector<ll>(1, 0));
    // vector<vector<ll>> b(s, vector<ll>(1, 0));
    a.push_back(vector<ll>());
    a[0].push_back(1);
    a[0].push_back(0);
    a[0].push_back(1);
    a[0].push_back(36);
    b.push_back(vector<ll>());
    b.push_back(vector<ll>());
    b.push_back(vector<ll>());
    b.push_back(vector<ll>());
    b[0].assign(4, 0);
    b[1].assign(4, 0);
    b[2].assign(4, 0);
    b[3].assign(4, 0);
    b[0][0] = 36;
    b[0][1] = 0;
    b[0][2] = 0;
    b[0][3] = 0;
    b[1][0] = 36;
    b[1][1] = 36;
    b[1][2] = 0;
    b[1][3] = 0;
    b[2][0] = 36;
    b[2][1] = 36;
    b[2][2] = 36;
    b[2][3] = 0;
    b[3][0] = 1;
    b[3][1] = 0;
    b[3][2] = 0;
    b[3][3] = 1;
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n == 0)
        {
            cout << "1\n";
            continue;
        }
        vector<vector<ll>> ans = mat_mul(a, mat_expo(b,n));
        cout << ans[0][0] << "\n";
    }
}