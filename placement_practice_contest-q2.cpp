#include<bits/stdc++.h>
using namespace std;
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
        long long h[n],a[n];long long m=1e9 + 7;
        for(int i=0;i<n;i++)
        {
            cin>>h[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            h[i] += a[i];
        }
        sort(h,h+n);
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
           (ans += h[i]*(i+1))%=m; 
        }
        cout<<ans<<"\n";
    }
}