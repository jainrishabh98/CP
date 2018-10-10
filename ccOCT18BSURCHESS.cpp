#include<bits/stdc++.h>
using namespace std;
int store[2][201][201][201];
int precalx[2][201][201][201];
int precaly[2][201][201][201];
int counter[40001];
int main ()
{
    int n,m;
    cin>>n>>m;
    int tempp;
    char x[m];
    int ds = min(m,n);
    store[2][(ds)+1][n+1][m+1]={0};
    precalx[2][ds+1][n+1][m+1] = {0};
    precaly[2][ds+1][n+1][m+1] = {0};
    for(int i=0;i<n;i++)
    {   //cin.get();
        cin>>x;
        for(int j=0;j<m;j++)
        {
            //cin>>x[j];
            tempp = x[j] - (int)('0');
            store[0][1][i+1][j+1]=abs(tempp-0);
            store[1][1][i+1][j+1]=abs(tempp-1);
            
        }
    }
    int q;
    cin>>q;
    int c[q];
    int max_size = ds*ds;
    counter[max_size+1]={1};
    for(int i=0;i<q;i++)
    {
        cin>>c[i];
    }
    for(int i=0;i<=1;i++)
    {
        for(int j=2;j<=m;j++)
            {
                //int p = abs(i-1);
                precaly[i][1][1][j]=store[i][1][1][j];
            }
    }
    for(int i=0;i<=1;i++)
    {
        for(int j=2;j<=n;j++)
            {
                //int p = abs(i-1);
                precalx[i][1][j][1]=store[i][1][j][1];
            }
    }
    for (int i=0;i<=1;i++)
    {
        for(int d=2;d<=ds;d++)
        {
            for(int x =1; x<=(n-d+1);x++)
            {
                for(int y=1; y<=(m-d+1);y++)
                {   
                    int ld = x+d-1;
                    int rd = y+d-1;
                    int p = abs(i-1);
                    precalx[i][d][ld][rd] = (store[i][1][ld][rd] + precalx[p][d-1][ld][rd-1]);
                    precaly[i][d][ld][rd] = (store[i][1][ld][rd] + precaly[p][d-1][ld-1][rd]);
                    store[i][d][x][y] = store[i][d-1][x][y] + (precalx[i][d][ld][rd] + precaly[i][d][ld][rd] - store[i][1][ld][rd]);
                    int temp = store[i][d][x][y];
                    counter[temp] = max(counter[temp],d);
                }
            }
        }
    }
    // int mx=0;
    // for(int i=0;i<=max_size;i++)
    // {
    //     mx = max(mx,counter[i]);
    // }
    // int i = max_size;
    // while(counter[i]==1 && i>=0)
    //     i--;
    // if(i!=-1)
    // {
    //     for(int j = i+1; j<=max_size; j++)
    //     {
    //         counter[j]=mx;
    //     }
    // }
    
    for(int i=0;i<q;i++)
    {
        if(c[i]> max_size)
            cout<<ds<<"\n";
        else
            cout<<counter[c[i]]<<"\n";
    }

    for (int i=0;i<=max_size;i++)
        cout<<counter[i]<<" ";
    return 0;
}