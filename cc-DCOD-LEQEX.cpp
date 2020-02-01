#include <bits/stdc++.h>
using namespace std;
typedef int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll c[n];
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
            c[i] = pow(2,c[i]-1);
        }
        unordered_map<ll, ll> ump;
        int x = 0,ans = 1;
        ump[0]=-1;
        for (int i = 0; i < n; i++)
        {
            x = x^c[i];
            int p = 1;
            for(int j=1;j<=30;j++)
            {
                if(ump.find(p^x)!=ump.end())
                {
                    ans =  max(ans,i - ump[p^x]);
                }
                p *= 2;
            }
            if(ump.find(x)==ump.end())
            {
                ump[x] = i;
            }
        }
        cout<<(ans-1)/2<<"\n";
    }
}
