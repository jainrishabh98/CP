#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    double p[n];
    for(int i=0;i<n;i++)    cin>>p[i];
    sort(p,p+n);
    double ans = p[n-1];
    if(ans==1) {cout<<ans;return 0;}
    double prod[n],sum[n];
    prod[n-1] = 1 - p[n-1];
    sum[n-1] = p[n-1]/(1-p[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        prod[i] = prod[i+1]*(1-p[i]);
        sum[i] = sum[i+1] + p[i]/(1-p[i]);
    }
    int i= n-1;
    while(sum[i]<1 && i>0) i--;
    ans = prod[i]*sum[i];
    cout<<fixed;
    cout<<setprecision(10)<<ans;
}