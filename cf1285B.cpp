#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll a[n];
        ll ans = 0,sum = 0,mx = -1e9 - 1,s = 0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            s += a[i];
            mx = max(mx,a[i]);
        }
        for(int i=1;i<n;i++)
        {
            sum += a[i];
            if(sum < 0)
                sum = 0;
            ans = max(ans,sum);
        }
        sum = 0;
        for(int i=0;i<n-1;i++)
        {
            sum += a[i];
            if(sum < 0)
                sum = 0;
            ans = max(ans,sum);
        }
        if(mx <= 0)
            ans = mx;
        if(ans >= s)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
        }
    }
}