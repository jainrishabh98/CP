#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,m;
    cin>>n>>m;
    int mn = min(n,m);
    mn++;
    cout<<mn<<"\n";
    int x=0,y=mn-1;
    while(mn--)
    {
        cout<<x<<" "<<y<<"\n";
        x++;
        y--;
    }

}