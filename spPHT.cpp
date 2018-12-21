#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ll n;
        cin>>n;
        ll ans = (int)(sqrt(n+1) - 1);
        // ll low = 1, high = 1e6;ll mid,ans = 0;
        // while(low<=high)
        // {
        //     mid = (low+high)/2;
        //     ll temp = mid*(mid+2);
        //     if(temp<=n)
        //         {low = mid+1;ans = max(ans,mid);}
        //     else
        //         high = mid-1;
            
        // }
        cout<<"Case "<<i<<": "<<ans<<"\n";
    }
    return 0;
}