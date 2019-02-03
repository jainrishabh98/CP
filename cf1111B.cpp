#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,m;
    cin>>n>>k>>m;
    double a[n],sum=0,l=n;
    for(int i=0;i<n;i++)
        {cin>>a[i];sum += a[i];}
    sort(a,a+n);
    for(int i=0;i<min(n-1,m);i++)
    {
        sum -= a[i];
        l--;
    }
    if(m>n-1)
    {
        m -= n-1;
        sum += min(k,m);
        cout<<fixed;
        cout<<setprecision(8)<<sum;
        return 0;
    }
    cout<<fixed;
    cout<<setprecision(8)<<sum/l;
    
}