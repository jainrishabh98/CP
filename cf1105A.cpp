#include<bits/stdc++.h>
using namespace std;
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    int cnt[101]={0};
    for(int i=0;i<n;i++)
        {cin>>a[i];
        cnt[a[i]]++;
}
    int mx = 1e8;
    int ans = 0;
    for(int t=1;t<=100;t++)
    {
    int c = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==t-1 || a[i]==t || a[i]==t+1) continue;
        else if(a[i]>t) c += a[i] - t - 1;
        else    c += t - 1 - a[i];
    }
    if(c < mx) {mx = c;ans = t;}
    }
    cout<<ans<<" "<<mx;
}