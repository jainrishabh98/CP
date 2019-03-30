#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int k;
    int s = a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]!=s)
        {
            k = i;
            break;
        }
    }
    cout<<k+1;
}