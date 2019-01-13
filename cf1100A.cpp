#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,k;
    cin>>n>>k;
    int x[n];
    int e=0,s=0;
    for(int i=0;i<n;i++)
        {cin>>x[i];if(x[i]==1) e++; else s++;}
    int ans = 0;
    for(int i=0;i<k;i++)
    {  int e1=e,s1=s;
        for(int j=i;j<n;j+=k)
        {
            if(x[j]==1) e1--;
            else s1--;
        }
        ans = max(ans,abs(e1-s1));
    }
    cout<<ans<<"\n";
}