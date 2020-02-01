#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    int a[n];
    ll cnt = 0, x;
    vector<ll> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a[i] = x;
        cnt += x;
    }
    ll anss = 1e15;
    for (ll i = 2; i * i <= cnt; i++)
    {
        if (cnt % i == 0)
        {
            vec.push_back(i);
            vec.push_back(cnt / i);
        }
    }
    if (cnt != 1)
        vec.push_back(cnt);
    for (auto i : vec)
    {
        vector<ll> ans;
        ll cost = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == 1)
            {
                ans.push_back(j + 1);
            }
            if (ans.size() == i)
            {
                ll med = ans[i / 2];
                while (!ans.empty())
                {
                    cost += abs(med - ans.back());
                    ans.pop_back();
                }
            }
        }
        anss = min(anss, cost);
    }
    if (anss == 1e15)
        cout << -1;
    else
        cout << anss;
}