#include<bits/stdc++.h>
using namespace std;
int  main ()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i] = 5 - a[i];
    }
    sort(a,a+n);
    int ind = lower_bound(a,a+n,k) -  a;
    cout<<(n-ind)/3;
}