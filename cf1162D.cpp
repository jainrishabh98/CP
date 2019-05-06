#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    map<pair<int, int>, int> mp;
    int a, b;
    int l[m], r[m];
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        l[i] = a;
        r[i] = b;
        if (b < a)
        {
            int c = b;
            b = a;
            a = c;
        }
        mp[{a, b}] = 1;
    }
    vector<int> d;
    d.push_back(1);
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            d.push_back(i);
            d.push_back(n / i);
        }
    }
    int flag=0;
    for (auto k : d)
    {
        flag=0;
        for (int i = 0; i < m; i++)
        {
            int a = (l[i] + k);
            int b = (r[i] + k);
            if(a>n) a-=n;
            if(b>n) b-=n;
            if (b < a)
            {
                int c = b;
                b = a;
                a = c;
            }
            if(mp.find({a,b})==mp.end())
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            break;
    }
    if(flag==0)
        cout<<"Yes";
    else
        cout<<"No";
}