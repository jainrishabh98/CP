#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll x;
        set<ll> s;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if(x%2==0)
            {
                s.insert(x);
            }
        }
        ll ans = 0;
        while(!s.empty())
        {
            ll num = *s.rbegin();
            s.erase(num);
            num /= 2;
            if(num%2==0)
            {
                s.insert(num);
            }
            ans++;
        }
        cout<<ans<<"\n";
    }
}