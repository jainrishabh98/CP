#include <bits/stdc++.h>
using namespace std;
int bit[100001];
int n;
void update(int k, int x)
{
    while (k <= n)
    {
        bit[k] += x;
        k += (k & (-k));
    }
}
long long int query(int k)
{
    long long int sum = 0;
    while (k >= 1)
    {
        sum += bit[k];
        k -= (k & (-k));
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, qu, m, p, q;
    cin >> t;
    vector<long long int> v;
    for (int x = 0; x <= 32; x++)
    {
        for (int y = x + 1; y <= 32; y++)
        {
            v.push_back(pow(2, x) + pow(2, y));
        }
    }
    sort(v.begin(), v.end());
    // for(auto i:v)
    //     cout<<i<<" ";
    while (t--)
    {  
        memset(bit,0,sizeof(bit));
        cin >> n;
        int g[n];
        for (int i = 0; i < n; i++)
        {
            cin >> g[i];
            if (binary_search(v.begin(), v.end(), g[i]))
            {
                update(i + 1, 1);
            }
        }
        cin >> qu;
        while (qu--)
        {
            cin >> m >> p >> q;
            if (m == 1)
            {
                if (binary_search(v.begin(), v.end(), g[p - 1]))
                    update(p, -1);
                g[p - 1] = q;
                if (binary_search(v.begin(), v.end(), g[p - 1]))
                    update(p, 1);
            }
            else
            {
                if (p > q)
                    cout << "0\n";
                else
                {
                    cout << query(q) - query(p - 1) << "\n";
                }
            }
        }
    }
}