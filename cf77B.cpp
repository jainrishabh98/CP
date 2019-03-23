#include<bits/stdc++.h>
using namespace std;
int main ()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        double a,b;
        cin>>a>>b;
        if(b==0)
            cout<<"1\n";
        else if(a==0)
            cout<<"0.5\n";
        else if(4*b >=a)
        {
            cout<<((b*a) + ((a*a)/8.0))/(2.0*b*a)<<"\n";
        }
        else
        {
            cout<<((double)1 - (b/a))<<"\n";
        }
    }
}