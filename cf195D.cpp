#include <bits/stdc++.h>
using namespace std;
long long int a[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long double k[n], b[n];
    set<long double> s;
    for (int i = 0; i < n; i++)
    {
        cin >> k[i] >> b[i];
        if (k[i] != 0)
            s.insert(-b[i] / k[i]);
    }
    int cnt = 1;
    map<long double, int> mp;
    for (auto k : s)
    {
        mp[k] = cnt;
        cnt++;
    }
    for (int i = 0; i < n; i++)
    {
        if(k[i]==0) continue;
        long double bb = -b[i] / k[i];
        int nnn = mp[bb];
        if (k[i] < 0)
        {
            a[nnn + 1] -= k[i];
            a[1] += k[i];
        }
        else if (k[i] > 0)
        {
            a[nnn + 1] += k[i];
        }
    }
    int cnn = 0;
    for (int i = 2; i <= cnt; i++)
    {
        a[i] += a[i - 1];
        if(a[i]-a[i-1]!=0)
            cnn++;
    }
    cout << cnn;
}