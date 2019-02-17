#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int p[n];
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        sum += p[i];
    }
    sort(p, p + n);
    vector<int> v[101];
    for(int i=1;i<=100;i++)
    {
        for (int j = 2; j*j <= i; j++)
        {
            if (i % j == 0)
            {
                v[i].push_back(j);
            }
        }
    }
    int add = 0, diff = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        for (auto k : v[p[i]])
        {
            if (((p[0] * k - p[0]) - (p[i] - p[i] / k)) < (add - diff))
            {
                add = (p[0] * k - p[0]);
                diff = (p[i] - p[i] / k);
            }
        }
    }
    cout << sum + add - diff;
}