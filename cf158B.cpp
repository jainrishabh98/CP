#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int s[n];
    int a[5] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        a[s[i]]++;
    }
    int ans = a[4];
    ans += a[3];
    a[1] = max(0,a[1]-a[3]);
    ans += a[2]/2;
    a[2] = a[2]%2;
    if(a[2])
    {
        ans ++;
        a[1] = max(0,a[1]-2);
    }
    ans += ceil(a[1]/4.0);
    cout<<ans;
}