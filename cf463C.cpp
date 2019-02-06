#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int a[n][n];
    int pre1[n][n]={0};
    int pre2[n][n]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum = 0;
        int x = i,y = 0;
        while(x>=0 && x<n && y>=0 && y<n)
        {
            sum += a[x][y];
            x += 1;
            y += 1;
        }
        x = i,y = 0;
        while(x>=0 && x<n && y>=0 && y<n)
        {
            pre1[x][y] = sum;
            x += 1;
            y += 1;
        }
    }
    for(int j=1;j<n;j++)
    {
        sum = 0;
        int x = 0,y = j;
        while(x>=0 && x<n && y>=0 && y<n)
        {
            sum += a[x][y];
            x += 1;
            y += 1;
        }
        x = 0,y = j;
        while(x>=0 && x<n && y>=0 && y<n)
        {
            pre1[x][y] = sum;
            x += 1;
            y += 1;
        }
    }
    for(int i=0;i<n;i++)
    {
        sum = 0;
        int x = i,y = n-1;
        while(x>=0 && x<n && y>=0 && y<n)
        {
            sum += a[x][y];
            x += 1;
            y -= 1;
        }
        x = i,y = n-1;
        while(x>=0 && x<n && y>=0 && y<n)
        {
            pre2[x][y] = sum;
            x += 1;
            y -= 1;
        }
    }
    for(int j=0;j<n-1;j++)
    {
        sum = 0;
        int x = 0,y = j;
        while(x>=0 && x<n && y>=0 && y<n)
        {
            sum += a[x][y];
            x += 1;
            y -= 1;
        }
        x = 0,y = j;
        while(x>=0 && x<n && y>=0 && y<n)
        {
            pre2[x][y] = sum;
            x += 1;
            y -= 1;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            
        }
    }
    
}