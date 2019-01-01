#include<bits/stdc++.h>
using namespace std;
int main ()
{   int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int g = a[1] - a[0];
    for(int i=2;i<n;i++)
        g = __gcd(g,a[i]-a[0]);
    int l = (a[n-1] - a[0])/g + 1;
    l = l - n;
    cout<<l<<"\n";
    return 0;
}