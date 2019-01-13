#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2)
        cout<<"Parallel to y-axis\n";
    else if(y1==y2)
        cout<<"Parallel to x-axis\n";
    else
        cout<<"None\n";
    return 0;
}