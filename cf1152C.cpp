#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a, b,x,k,t1,t2;
    cin >> a >> b;
    if (b < a)
    {
        int c = b;
        b = a;
        a = c;
    }
    x = b-a;
    k = 0;
    long long int anss = (a*b)/__gcd(a,b);
    for (long long int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            long long int c = i;
            for(int kk=0;kk<=1;kk++)
            {
            t1 = a;
            t2 = b;
            if(t1%c!=0)
            {
            t1 += (c-t1%c);
            t2 += (c-t2%c);
            }
            long long int lcm = (t1*t2)/__gcd(t1,t2);
            // cout<<c<<" "<<lcm<<"\n";
            if(lcm < anss)
            {
                anss = lcm;
                k = t1 - a;
            }
            else if(lcm==anss)
                k = min(k,t1-a);
            c = x/i;
            }
        }
    }
    cout<<k;
}