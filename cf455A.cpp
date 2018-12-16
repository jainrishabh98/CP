#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll store[100001];
ll dp[100001];
int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    memset(store,0,sizeof(store));
    int n,z,mx=INT_MIN;
    cin>>n;
    for(int i=0;i<n;i++)
       { cin>>z;
         mx = max(z,mx);
         store[z] = store[z] + z;
       } 
    for(int itr=1;itr<=mx;itr++)
    {
        if(itr==1)
            dp[itr] = store[itr];
        
        else if(itr==2)
            dp[itr] = max(dp[itr-1],store[itr]);
        
        else
            dp[itr] = max(dp[itr-2]+store[itr],dp[itr-1]);
    }
    cout<<dp[mx]<<"\n";
    return 0;
}