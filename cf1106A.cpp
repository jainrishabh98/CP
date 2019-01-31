#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    char x;
    int a[n+2][n+2]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>x;
            if(x=='X')
                a[i][j]=1;
        }
        
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==1)
            {
                if(a[i-1][j-1]==1 && a[i-1][j+1]==1 && a[i+1][j-1]==1 && a[i+1][j+1]==1 )
                {
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;

}