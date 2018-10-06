#include <bits/stdc++.h>
using namespace std;
typedef long long int ull;
struct st
{
    ull a;
    ull b;
    ull p;
};
bool comp(st c, st d)
{
    return (c.p < d.p);
}
int main()
{
    int n;
    ull m;
    cin >> n >> m;
    st s[n];

    for (int i = 0; i < n; i++)
        cin >> s[i].a;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].b;
        s[i].p = s[i].a * s[i].b;
    }
    sort(s,s+n,comp);
    if (m == 0)
    {
        cout << s[n - 1].p << "\n";
        return 0;
    }
    ull low = 0, high = 1e18, mid = 0, ans = 0, sum = 0;
    ull mx =0;
    while (low <= high)
    {
        mx=0;
        mid = (high + low) / 2;
        sum = 0;
        // cout<<mid<<"\n";
        for (int i = 0; i < n; i++)
        {
            if (s[i].p >= mid)
            {
                sum += ceil((double)(s[i].p - mid) / (double)(s[i].b));
                mx = max(mx,s[i].p - (ull)(ceil((double)(s[i].p-mid)/(double)(s[i].b)))*s[i].b);
            }
        }
       
        if (sum > m)
        {
            low = mid + 1;
        }
        else
        {
            ans = mx;
            high = mid - 1;
        }
        
    }
    
    cout << ans << "\n";
    
    return 0;
}