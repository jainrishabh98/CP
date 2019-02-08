#include<bits/stdc++.h>
using namespace std;
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n][n];
    long long int pre1[n][n]={0};
    long long int pre2[n][n]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    long long int sum=0;
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
    long long int mx1=-1,mx2=-1;
    int x1,y1,x2,y2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(((i+j)&1)==0)
            {
                if(mx1 < pre1[i][j] + pre2[i][j]-a[i][j])
                {
                    mx1 = pre1[i][j] + pre2[i][j]-a[i][j];
                    x1 = i;
                    y1 = j;
                }
            }
            else
            {
                if(mx2 < pre1[i][j] + pre2[i][j]-a[i][j])
                {
                    mx2 = pre1[i][j] + pre2[i][j]-a[i][j];
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }
    cout<<mx1+mx2<<"\n";
    cout<<x1+1<<" "<<y1+1<<" "<<x2+1<<" "<<y2+1;
}