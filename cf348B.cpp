#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
long long int a[100005];
long long int ans = 0;
long long int gc[100005];
long long int gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    a %= b;
    return gcd(b, a);
}
void dfs(int u, int par)
{
    long long int temp = 1000000000000000;
    long long int lcm = 1;
    for (auto i : g[u])
    {
        if (i != par)
        {
            dfs(i, u);
            temp = min(temp, a[i]);
            lcm = (lcm * gc[i]) / gcd(lcm, gc[i]);
        }
    }
    if (lcm != 0)
    {
        temp = temp / lcm;
        temp = temp * lcm;
    }
    for (auto i : g[u])
    {
        if (i != par)
        {
            ans += (a[i] - temp);
            a[u] += temp;
        }
    }
    if (g[u].size() == 1)
    {
        gc[u] = 1;
    }
    else
        gc[u] = lcm * (g[u].size() - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x, y;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1);
    cout << ans;
}