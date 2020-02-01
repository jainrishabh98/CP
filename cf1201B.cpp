#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll a[n];
    ll sum = 0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    sort(a,a+n);
    if(sum%2!=0 || a[n-1]*2 > sum)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
    return 0;
}