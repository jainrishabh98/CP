#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mn = 1000,mx = 0,p1=-1,p2=-1;
        int x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x < mn)
            {
                mn = x;
                p1 = i;
            }
            if(x >= mx)
            {
                mx = x;
                p2 = i;
            }
        }
        if(p1 < p2)
            cout<<mn<<" "<<mx<<"\n";
        else
        {
            cout<<mx<<" "<<mn<<"\n";
        }
        
    }
}