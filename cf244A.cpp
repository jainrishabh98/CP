#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,k;
    cin>>n>>k;
    int a[k+1];
    int vis[1000]={0};
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
        vis[a[i]]=1;
    }   
    int j=1;
    for(int i=1;i<=k;i++)
    {
        cout<<a[i]<<" ";
        int cnt = 1;
        while(cnt!=n)
        {
            if(vis[j]==0)
            {
                vis[j]=1;
                cnt++;
                cout<<j<<" ";
            }
            j++;
        }
        cout<<"\n";
    }
}