#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    // if(n%4!=0 && n%7!=0 && (n%7)%4!=0 && (n%4)%7!=0) {cout<<"-1";return 0;}
    int x = 0,y = n/7;
    if(n%7==1)
    {
        x = 2;
        y = n/7 - 1 ;
    }
    else if(n%7==2)
    {
        x = 4;
        y = n/7 - 2 ;
    }
    else if(n%7==3)
    {
        x = 6;
        y = n/7 - 3;
    }
    else if(n%7==4)
    {
        x = 1;
        y = n/7;
    }
    else if(n%7==5)
    {
        x = 3;
        y = n/7 - 1 ;
    }
    else if(n%7==6)
    {
        x = 5;
        y = n/7 - 2 ;
    }
    if(y<0) {cout<<"-1";return 0;}
    for(int i=1;i<=x;i++)
        cout<<"4";
    for(int i=1;i<=y;i++)
        cout<<"7";
    
}