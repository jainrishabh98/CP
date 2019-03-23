#include<bits/stdc++.h>
using namespace std;
int main ()
{
    double a,b,m;
    cin>>a>>b>>m;
    double vx,vy,vz;
    cin>>vx>>vy>>vz;
    double t = m/abs(vy);
    double z0 = 0;
    if(vz!=0)
    {
        int temp  = (t*vz)/b;
        if(temp%2==0)
        {
            z0 = t*vz - temp*b;
        }
        else
        {
            z0 = b - (t*vz - temp*b);
        }
    }
    double x0 = a/2;
    if(vx!=0)
    {
        
        if (t < a/(2*abs(vx)))
        {
            if(vx < 0)
            {
                x0 -= t*abs(vx);
            }
            else
            {
                x0 += t*abs(vx);
            }
        }
        else
        {
        t -= a/(2*abs(vx));
        int temp  = (t*abs(vx))/a;
        if((temp%2==0 && vx<0) || (temp%2==1 && vx>0))
        {
            x0 =t*abs(vx) - temp*a;
        }
        else
        {
            x0 = a - (t*abs(vx) - temp*a);
        }
        }
    }
    cout<<fixed;
    cout<<setprecision(7)<<x0<<" "<<z0;
}