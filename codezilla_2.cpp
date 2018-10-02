#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,q;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>q;
        int y[m];
        //memset(x,0, sizeof(x));
        memset(y,0, sizeof(y));
        
        while(q--)
        {   int a,b;
            cin>>a>>b;
            y[b] = 1;
        }
        int mark1=0;
        int mark2 = 0;
        for(int i=0;i<m;i++)
        {
            if(y[i]==1)
                {
                    mark1 = i;
                    break;
                }
        }
        
        for(int i=m-1;i>=0;i--)
        {
            if(y[i]==1)
                {
                    mark2 = i;
                    break;
                }
        }
        cout<<mark2-mark1<<"\n";
    }
}