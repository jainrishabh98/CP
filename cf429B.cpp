#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    long long int dp1[n][m];
    long long int dp2[n][m];
    long long int dp3[n][m];
    long long int dp4[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0) dp1[i][j]=a[i][j];
            else if(i==0) dp1[i][j] = a[i][j] + dp1[i][j-1];
            else if(j==0) dp1[i][j] = a[i][j] + dp1[i-1][j];
            else dp1[i][j] = a[i][j] + max(dp1[i-1][j],dp1[i][j-1]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i==0 && j==m-1) dp2[i][j]=a[i][j];
            else if(i==0) dp2[i][j] = a[i][j] + dp2[i][j+1];
            else if(j==m-1) dp2[i][j] = a[i][j] + dp2[i-1][j];
            else dp2[i][j] = a[i][j] + max(dp2[i-1][j],dp2[i][j+1]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0) dp1[i][j]=a[i][j];
            else if(i==0) dp1[i][j] = a[i][j] + dp1[i][j-1];
            else if(j==0) dp1[i][j] = a[i][j] + dp1[i-1][j];
            else dp1[i][j] = a[i][j] + max(dp1[i-1][j],dp1[i][j-1]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0) dp1[i][j]=a[i][j];
            else if(i==0) dp1[i][j] = a[i][j] + dp1[i][j-1];
            else if(j==0) dp1[i][j] = a[i][j] + dp1[i-1][j];
            else dp1[i][j] = a[i][j] + max(dp1[i-1][j],dp1[i][j-1]);
        }
    }
}