#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long int n,k;double m;
    cin>>n>>m>>k;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long int ans = 0,sum = 0,l=0;
    for(int i=0;i<n;i++)
    {
        sum += a[i];
        if(ceil(l/m)!=ceil((l+1)/m))
        {
            sum -= k;
        }
        l++;
        if(sum < 0)
        {
            sum = 0;
            l  = 0;
        }
        ans = max(ans,sum);
    }
    cout<<ans;
    return 0;
}