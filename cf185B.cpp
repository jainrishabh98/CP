#include<bits/stdc++.h>
using namespace std;
int main ()
{
    double s;
    cin>>s;
    double a,b,c;
    cin>>a>>b>>c;
    double ss = a+b+c;
    if(ss==0)
    {
        cout<<0<<" "<<0<<" "<<0;
        return 0;
    }
    cout<<fixed;
    cout<<setprecision(15)<<(s*a)/ss<<" "<<(s*b)/ss<<" "<<(s*c)/ss;
}