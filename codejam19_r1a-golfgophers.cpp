#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t,n,m;
    cin>>t>>n>>m;
    while(t--)
    {
        int a[] = {16,9,5,7,11,13,17};
        int cnt[7]={0};
        int b[7][18];
        for(int j=0;j<7;j++)
        {
        for(int i=0;i<18;i++)
        {
            cout<<a[j]<<" ";
        }
        cout<<endl;
        for(int i=0;i<18;i++)
        {
            cin>>b[j][i];
            cnt[j] += b[j][i];
        }
        cnt[j] = cnt[j]%a[j];
        }
        int ans;
        for(int i=1;i<=m;i++)
        {
            int flag=0;
            for(int j=0;j<7;j++)
            {
                if(i%a[j] != cnt[j])
                    flag=1;
            }
            if(flag==0)
            {
                ans = i;
                break;
            }
        }
        cout<<ans<<endl;
        int x;
        cin>>x;
        if(x==-1)
            return 0;
    }
}