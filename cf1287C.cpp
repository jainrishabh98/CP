#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int p[n];
    int a[2] = {0};
    a[0] = a[1] = n / 2;
    if (n % 2 != 0)
        a[1]++;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (p[i] > 0)
            a[p[i] % 2]--;
    }
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    int ans = 0;
    int prev = p[0], in = 0;
    vector<pair<int, int>> v;
    for (int i = 1; i < n; i++)
    {
        if (p[i] != 0)
        {
            if (prev == 0)
            {
                prev = p[i];
                in = i;
                continue;
            }
            if ((prev + p[i]) % 2 == 0)
            {
                v.push_back({i - in - 1, p[i] % 2});
            }
            else
                ans++;
            prev = p[i];
            in = i;
        }
    }
    if (prev == 0)
    {
        cout << 1;
        return 0;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (a[v[i].second] >= v[i].first)
            a[v[i].second] -= v[i].first;
        else
            ans += 2;
    }
    v.clear();
    int i = 0;
    while (p[i] == 0)
        i++;
    v.push_back({i, p[i] % 2});
    i = n - 1;
    while (p[i] == 0)
        i--;
    v.push_back({n - 1 - i, p[i] % 2});
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (a[v[i].second] >= v[i].first)
            a[v[i].second] -= v[i].first;
        else
            ans += 1;
    }
    cout << ans;
}