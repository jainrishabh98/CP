#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll n;
    cin>>n;
    ll a[n],b[5],c[5]={0};
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<5;i++)
        cin>>b[i];
    ll sum=0;
    for(int i=0;i<n;i++)
    {   sum += a[i];
        for(int j=4;j>=0;j--)
        {
        c[j] += (sum/b[j]);
        sum -= (sum/b[j])*b[j];
        }
    }
    for(int i=0;i<5;i++)
        cout<<c[i]<<" ";
    cout<<"\n"<<sum<<"\n";
    return 0;
}