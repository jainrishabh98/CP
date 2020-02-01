#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    cin >> n>>k;
    ll a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int i=0,j=0;
    ll sum = 0;
    ll ans = k;
    while(j<n)
    {
        while(sum < k && j<n)
        {
            sum += a[j];
            ans = min(ans,abs(k - sum));
            j++;
        }
        ans = min(ans,abs(k - sum));
        sum -= a[i];
        ans = min(ans,abs(k - sum));
        i++;
    }
    cout<<ans;
}