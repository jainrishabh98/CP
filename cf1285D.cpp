#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll s[100001][31];
ll rec(int i, vector<int> v)
{
    if (i == -1)
        return 0;
    ll x = 1, y = 0;
    vector<int> v1, v2;
    ll ans = 0;
    for (int j = 0; j < v.size(); j++)
    {
        x = x & s[v[j]][i];
        y = y | s[v[j]][i];
        if (s[v[j]][i] == 0)
            v1.push_back(v[j]);
        else
            v2.push_back(v[j]);
    }
    if (x == 1)
    {
        ans = rec(i - 1, v2);
    }
    else if (y == 0)
    {
        ans = rec(i - 1, v1);
    }
    else
    {
        ans = pow(2,i) + min(rec(i - 1, v1), rec(i - 1, v2));
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector <int> v;
    ll x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        int cn = 0;
        while (x != 0)
        {
            if (x % 2 != 0)
                s[i][cn] = 1;
            cn++;
            x /= 2;
        }
        v.push_back(i);
    }
    cout<<rec(30,v);
}