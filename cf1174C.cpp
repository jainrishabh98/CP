#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int ans[n+1]={0};
    int val=1;
    int i=2;
    while(i<=n)
    {
        if(ans[i]==0)
        {
            for(int j=i;j<=n;j+=i)
            {
                ans[j] = val;
            }
            val++;
        }
        i++;
    }
    for(int i=2;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
}