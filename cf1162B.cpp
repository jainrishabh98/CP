#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,m;
    cin>>n>>m;
    int a[n][m],b[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>b[i][j];
        }
    }
    int flag = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((min(a[i][j],b[i][j]) >= min(a[i+1][j],b[i+1][j]) || max(a[i][j],b[i][j]) >= max(a[i+1][j],b[i+1][j])) && i!=n-1) 
            {
                flag = 1;
                break;
            }
            if((min(a[i][j],b[i][j]) >= min(a[i][j+1],b[i][j+1]) || max(a[i][j],b[i][j]) >= max(a[i][j+1],b[i][j+1])) && j!=m-1) 
            {
                flag = 1;
                break;
            }
        }
    }
    if(flag==0)
        cout<<"Possible";
    else
        cout<<"Impossible";
    
}