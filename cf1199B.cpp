#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double h,l;
    cin>>h>>l;
    double t = (l*l)/(2*h);
    cout<<fixed;
    cout<<setprecision(10)<<(t - h/2.0);
}