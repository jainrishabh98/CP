#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<ll, ll> mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, t;
    cin >> n >> t;
    vector<ll> a;
    ll x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (mp.find(x) == mp.end())
        {
            mp[x] = 1;
            a.push_back(x);
        }
        else
        {
            mp[x]++;
        }
    }
    sort(a.begin(), a.end());
    ll k = (t * 8) / n;
    ll s = a.size();
    ll K = 1;
    for(int i=1;i<=k;i++)
    {
        K *= 2;
        if(K >= s)
            break;
    }
    ll pre[s];
    pre[0] = 0;
    for(int i=1;i<s;i++)
    {
        pre[i] = mp[a[i-1]] + pre[i-1];
    }
    ll suf[s];
    suf[s-1] = 0;
    for(int i=s-2;i>=0;i--)
    {
        suf[i] = mp[a[i+1]] + suf[i+1];
    }
    ll ans = n;
    for(int i=0;i<s;i++)
    {
        int j = i+min(s-1,K-1);
        ans = min(ans,pre[i] + suf[j]);
    }
    cout<<ans;
}