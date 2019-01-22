#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int a[n];
    vector <int> v;
    int x;
    int mx=0;
    for(int i=0;i<n;i++)    {cin>>a[i];mx=max(mx,a[i]);}
    for(int i=0;i<n;i++)    
    {cin>>x;
     if(a[i]!=mx)
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    sort(a,a+n);
    int freq = upper_bound(a,a+n,mx) - lower_bound(a,a+n,mx) + 1;
    int m=n;
    long long int ans = 0;
    int i=0;
    while(freq <= (m/2) && i<v.size())
    {
        ans += v[i];
        i++;
        m--;
    }
    cout<<ans;
}