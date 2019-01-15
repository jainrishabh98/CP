#include<bits/stdc++.h>
using namespace std;
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int s[n];
    double x[n];
    for(int i=0;i<n;i++)
        cin>>s[i]>>x[i];
    
    int lis[n];
    lis[0]=1;
    int ans=1;
    for (int i=1;i<n;i++)
    {   lis[i]=1;
        for(int j=0;j<i;j++)
        {
            if(s[i]>=s[j] && lis[i] < lis[j]+1)
                lis[i] = lis[j] + 1;
        }
        ans = max(ans,lis[i]);
    }
    cout<<n-ans<<"\n";
    return 0;

}