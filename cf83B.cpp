#include <bits/stdc++.h>
using namespace std;
struct st
{
    long long int a;
    int b;
};
bool comp(st x, st y)
{
    return (x.a == y.a) ? (x.b < y.b) : (x.a < y.a);
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long int n, k;
    cin >> n >> k;
    st a[n];
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].a;
        sum += a[i].a;
        a[i].b = i;
    }
    if (sum < k)
    {
        cout << -1;
        return 0;
    }
    sort(a, a + n, comp);
    int i = 0;
    long long int ss = 0;
    for (; i < n; i++)
    {
        if (ss + a[i].a * (n - i) <= k)
        {
            ss += a[i].a;
        }
        else
            break;
    }
    long long int rem = 0;
    i--;
    if(i!=-1)
    {
    ss -= a[i].a;
    k -= ss + a[i].a * (n - i);
    rem = a[i].a;
    }
    queue<pair<int, long long int>> q;
    set<pair<int, long long int>> s;
    for (int j = i + 1; j < n; j++)
    {
        s.insert({a[j].b, a[j].a - rem});
    }
    for (auto m : s)
    {
        q.push({m.first, m.second});
    }
    if (!q.empty())
    {
        int l = q.size();
        long long int sub = k / l;
        k = k % l;
        for (int i = 1; i <= l; i++)
        {
            long long int p = q.front().second;
            int in = q.front().first;
            q.pop();
            p -= sub;
            if (p != 0)
            {
                q.push({in, p});
            }
        }
        for (int i = 1; i <= k; i++)
        {
            long long int p = q.front().second;
            int in = q.front().first;
            q.pop();
            p--;
            if (p != 0)
            {
                q.push({in, p});
            }
        }
        while (!q.empty())
        {
            cout << q.front().first + 1 << " ";
            q.pop();
        }
    }
}