#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[1000001], b[1000001], ans[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            ans[i] = -1;
        }
        for (int i = 1; i <= m; i++)
            cin >> b[i];

        for (int i = 1; i <= m; i++)
        {
            for (int j = i; j <= n; j += i)
            {
                if (ans[j] == -1 && a[j] <= b[i])
                {
                    ans[j] = i;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<"\n";
        }
    }
}