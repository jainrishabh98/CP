#include<bits/stdc++.h>
using namespace std;
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,t,x,y,z;
        cin>>n>>t>>x>>y>>z;
        int tn = (2*n + 1);
        int am;
        if(t==1)
        {
            if(y-x==1 && y-z==1)
                am = y-1;
            else if(x-y==1 && y-z==1)
                am = 2*n + 2 -y;
            else if(x-y==1 && z-y==1)
                am = y+1;
            else
                am = 2*n - y;
            
        }
        else if (t==2 || t==4)
            am = 2*n+ 1 - (2*y);
        
        else
        {
            if(y-x==1 && z-y==1)
                am = 2*n + 2 -y; 

            else if(x-y==1 && z-y==1)
                am = y+1;
            
            else if(y-x==1 && y-z==1)
                am = y-1;
            
            else
                am = 2*n - y;
            
        }
        int g = __gcd(am,tn);
        am /= g;
        tn /= g;
        cout<<am<<" "<<tn<<"\n";

    }
    return 0;
}