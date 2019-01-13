#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long double n,r;
    cin>>n>>r;
    long double t = 3.1415926;
    long double ans  = (sin(t/n)*r)/(1-sin(t/n));
    cout<<fixed;
    cout<<ans<<setprecision(7)<<"\n";
    return 0;
}