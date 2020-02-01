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
        ll n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        ll cn[n];
        cn[0] = 0;
        if (s[0] == '0')
            cn[0]++;
        for (int i = 1; i < n; i++)
        {
            cn[i] = cn[i - 1];
            if (s[i] == '0')
                cn[i]++;
        }
        ll cnt = n - cn[n - 1];    // count of 1
        ll diff = cn[n - 1] - cnt; // 0s - 1s

        if (diff == 0)
        {
            ll fl = 0;
            for (int i = 0; i < n; i++)
            {
                if ((cn[i] - (i + 1 - cn[i])) == x)
                {
                    fl = -1;
                    break;
                }
            }
            cout<<fl<<"\n";
        }
        else
        {
            ll ans= 0;
            if(x==0)
                ans++;
            for (int i = 0; i < n; i++)
            {
                ll p = (cn[i] - (i + 1 - cn[i]));
                if(diff > 0)
                {
                    if(x>=p)
                    {
                        if((x-p)%diff==0)
                            ans++;
                    }
                }
                else
                {
                    if(x<=p)
                    {
                        if((p-x)%abs(diff)==0)
                            ans++;
                    }
                }
                
                
            }
            cout<<ans<<"\n";
        }
    }
}