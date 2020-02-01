#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int h,w;
    cin>>h>>w;
    int a[h][w];
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            a[i][j] = 0;
        }
    }
    int r,c;
    for(int i=0;i<h;i++)
    {
        cin>>r;
        for(int j=0;j<r;j++)
        {
            a[i][j] = 1;
        }
        if(r<w)
        {
            a[i][r] = 2;
        }
    }
    for(int i=0;i<w;i++)
    {
        cin>>c;
        for(int j=0;j<c;j++)
        {
            if(a[j][i]==2)
            {
                cout<<0;
                return 0;
            }
            a[j][i] = 1;
        }
        if(c<h)
        {
            if(a[c][i]==1)
            {
                cout<<0;
                return 0;
            }
            a[c][i] = 2;
        }
    }
    long long ans = 1,m = 1e9 + 7;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(a[i][j]==0)
            {
                (ans *= 2)%=m;
            }
        }
    }
    cout<<ans;
}