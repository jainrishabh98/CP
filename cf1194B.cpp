#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        int n,m;
        cin>>n>>m;
        char x;
        int cnr[n],cnc[m]={0},a[n][m];
        for(int i=0;i<n;i++)
        {
            cnr[i]=0;
            for(int j=0;j<m;j++)
            {
                cin>>x;
                if(x=='.')
                {
                    a[i][j]=1;
                    cnr[i]++;
                    cnc[j]++;
                }
                else
                    a[i][j]=0;
            }
        }
        int ans = n*m;
        for(int i=0;i<n;i++)
        {   int temp = cnr[i];
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==0)
                {
                    ans = min(ans,temp+cnc[j]);
                }
                else
                {
                    ans = min(ans,temp + cnc[j]-1);
                }
            }
        }
        cout<<ans<<"\n";
    }
}