#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,z;
    cin>>n>>z;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int ans = 0;
    int j = n-1;
    for(int i=(n/2)-1;i>=0;i--)
    {
        if(a[i]+z<=a[j])
        {
            ans++;
            j--;
        }
    }
    cout<<ans;
}