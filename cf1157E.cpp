#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n],c[n];
    int x;
    multiset <int> b;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        b.insert(x);
    }
    for(int i=0;i<n;i++)
    {
        int t1 = (a[i]+*b.begin())%n;
        int t = n - a[i];
        int t2 = t1 + 1;
        auto pos = b.lower_bound(t);
        if(pos!=b.end())
        {
        t2 = *pos;
        t2 = (t2 + a[i])%n;
        }
        if(t2<t1)
        {
            c[i] = t2;
            b.erase(pos);
        }
        else
        {
            c[i] = t1;
            b.erase(b.begin());
        }
        cout<<c[i]<<" ";
    }
}