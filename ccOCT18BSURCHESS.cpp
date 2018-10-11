#include<bits/stdc++.h>
using namespace std;
int store[2][2][200][200] = {0};
int precalx[2][2][200][200] = {0};
int precaly[2][2][200][200] = {0};

int main ()
{
    int n,m;
    cin>>n>>m;
    int tempp;
    char x[m];
    int ds = min(m,n);
    for(int i=0;i<n;i++)
    {   
        cin>>x;
        for(int j=0;j<m;j++)
        {
            
            tempp = x[j] - (int)('0');
            store[0][0][i][j]=abs(tempp-0);
            store[1][0][i][j]=abs(tempp-1);
            store[0][1][i][j]=store[0][0][i][j];
            store[1][1][i][j]=store[1][0][i][j];
            precalx[0][0][i][j]=store[0][0][i][j];
            precalx[0][1][i][j]=precalx[0][0][i][j];
            precalx[1][0][i][j]=store[1][0][i][j];
            precalx[1][1][i][j]=precalx[1][0][i][j];
            precaly[0][0][i][j]=store[0][0][i][j];
            precaly[0][1][i][j]=precaly[0][0][i][j];
            precaly[1][0][i][j]=store[1][0][i][j];
            precaly[1][1][i][j]=precaly[1][0][i][j];
            
        }
    }
    int q;
    cin>>q;
    int c[q];
    
    for(int i=0;i<q;i++)
    {
        cin>>c[i];
    }

    int counter[(ds*ds)+1]={1};
   
    int temp,ld,rd,p;
    
    for(int d=2;d<=ds;d++)
    {   
          
            for(int x =0; x<(n-d+1);x++)
            {
                for(int y=0; y<(m-d+1);y++)
                {   
                    for(int i=0;i<=1;i++)
                    { 
                    ld = x+d-1;
                    rd = y+d-1;
                    p = abs(i-1);
                    precalx[i][1][ld][rd] = (store[i][0][ld][rd] + precalx[p][0][ld][rd-1]);
                    precaly[i][1][ld][rd] = (store[i][0][ld][rd] + precaly[p][0][ld-1][rd]);
                    store[i][1][x][y] = store[i][1][x][y] + (precalx[i][1][ld][rd] + precaly[i][1][ld][rd] - store[i][0][ld][rd]);
                    
                    temp = store[i][1][x][y];
                    counter[temp] = max(counter[temp],d);
                    precalx[p][0][ld][rd-1] = precalx[p][1][ld][rd-1];
                    precaly[p][0][ld-1][rd] = precaly[p][1][ld-1][rd];
                    }
                }
            
            }        
    }

     for (int i=1;i<=(ds*ds);i++)
        {counter[i] = max(counter[i],counter[i-1]);
         //cout<<counter[i]<<" ";
        }
    //cout<<"\n";
    for(int i=0;i<q;i++)
    {
        if(c[i]> (ds*ds))
            cout<<ds<<"\n";
        else
            cout<<counter[c[i]]<<"\n";
    }

   
    return 0;
}