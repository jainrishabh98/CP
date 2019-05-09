#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    long long int mx,mn = 0,ans = 0,best = 0;
    long long int sum[n],left[n],right[n+1];
    for (int i = 0; i < n; i++)
        cin >> sum[i];
    right[n] = 0;
    for(int i=1;i<n;i++)
    {
        sum[i] += sum[i-1];
    }
    for(int i=0;i<n;i++)
    {
        mn = min(mn,sum[i]);
        left[i] = sum[i] - mn;
        ans = max(ans,left[i]);
    }
    mx = sum[n-1];
    for(int i=n-1;i>0;i--)
    {
        mx = max(mx,sum[i]);
        right[i] = max((long long int)0,mx - sum[i-1]);
    }
    right[0] = max(mx,sum[0]);
    for(int i=0;i<n;i++)
    {
        ans = max(ans,x*sum[i] + right[i+1] + best);
        best = max(best,left[i] - x*sum[i]);
    }
    cout<<ans;
}