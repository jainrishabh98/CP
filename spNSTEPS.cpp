#include<bits/stdc++.h>
using namespace std;
int main ()
{   int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(x!=y && x!=(y+2))
            cout<<"No Number\n";
        else 
        {
           int temp = (x+y)/2;
           if(temp%2 == 0)
           {
               if(x==y) cout<<x+y<<"\n";
               else cout<<x+y-1<<"\n";
           } 
           else
           {
               if(x==y) cout<<x+y-1<<"\n";
               else cout<<x+y<<"\n";
           }
        }
    }
    return 0;
}