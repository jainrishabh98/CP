#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {   
        int n,m,x;
        cin>>n>>m;
        int mx1 = 0, mx2 = 0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            mx1 = max(mx1,x);
        }
         for(int i=0;i<m;i++)
        {
            cin>>x;
            mx2 = max(mx2,x);
        }
        if(mx1 < mx2)
        {
            cout<<"MechaGodzilla\n";
        }
        else
            cout<<"Godzilla\n";
    }
    return 0;
}