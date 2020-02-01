#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string ans,s;
ll mod = 1e14 + 23, mul = 257;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cin>>ans;
    for (int i = 1; i < n; i++)
    {
        cin>>s;
        int l = min(ans.length(), s.length());
        int pp = ans.length(),len = 0;
        ll hs = 0, hsh = 0, p = 1;
        for (int j = 0; j < l; j++)
        {
            hs = ((hs * mul) % mod + (ll)(s[j])) % mod;
            (hsh += ((ll)(ans[pp - j - 1]) * p) % mod) %= mod;
            p = (p*mul)%mod;
            if(hs == hsh)
            {
                len = j+1;
            }
        }
        ans.append(s.substr(len,s.length()-len));
    }
    cout << ans;
}