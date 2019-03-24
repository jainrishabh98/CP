#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m, n, x;
map<ll, ll> mp;
ll f[200005];
ll a[100005];
ll b[100005];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a[i] = x;
        mp[x]++;
        
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        b[i] = x;
        mp[x]++;
    }
    cin >> m;
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            cnt++;
        }
    }
    f[0] = 1;
    for (int i = 1; i <= 2 * n; i++)
    {
        f[i] = (f[i - 1] * i) % m;
    }
    ll ans = 1;
    // cout<<cnt<<"\n";
    for (auto j : mp)
    {
        if(cnt!=0)
        {
        for(int i=1;i<=j.second;i++)
        {   int xx = i;
            while(xx%2==0 && cnt!=0)
            {
                cnt--;
                xx /= 2;
            }
            (ans *= xx)%=m;
        }
        }
        else
        (ans *= f[j.second]) %= m;
    }
    cout << ans;
}