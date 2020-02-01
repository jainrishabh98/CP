#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r,c;
    cin>>r>>c;
    if(r==1 && c==1)
    {
        cout<<0;
    }
    else if(r==1 || c==1)
    {
        ll cn = 2;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout<<cn<<" ";
                cn++;
            }
            cout<<"\n";
        }
    }
    else
    {
        ll a[r][c];
        ll cn = 0;
        for(int i=0;i<r;i++)
        {   cn++;
            for(int j=0;j<c;j++)
            {
                a[i][j] = cn; 
            }
        }
        for(int i=0;i<c;i++)
        {   cn++;
            for(int j=0;j<r;j++)
            {
                a[j][i] *= cn; 
            }
        }
        for(int i=0;i<r;i++)
        {   
            for(int j=0;j<c;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    
}