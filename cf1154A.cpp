#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int a[4],e,f,g;
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    sort(a,a+4);
    e = a[3] - a[2];
    f = abs(a[1] - e);
    g = abs(a[0] - e);
    cout<<e<<" "<<f<<" "<<g;
}