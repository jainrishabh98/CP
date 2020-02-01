#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        int ans = min(a[0],(a[2] - a[1]));
        a[0] -= ans;
        a[2] -= ans;
        a[1] -= a[0]/2;
        a[2] -= a[0]/2;
        if(a[0]&1)
            a[1]--;
        ans += a[0];
        ans += a[1];
        cout<<ans<<"\n";
    }
}