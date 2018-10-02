#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long int n,a,b,c;
    cin>>n;
    if(n==3)
    {
        cout<<"1 1 1\n";
        return 0;
    }
    if (n%3==0)
    {   if((n/3)%3!=0)
            a = b = c = n/3;
        else
        {
            a = (n/3) + 2;
            b = c = (n/3) -1;
        }
    }
    else
    {
        a = n%3;
        n = n - a;
        if((n/3)%3!=0)
            {
                b = 2*(n/3);
                c = n/3;
            }
        else
        {
            b =  2*(n/3) - 1;
            c = (n/3) + 1;
        }
    }
    cout<<a<<" "<<b<<" "<<c<<"\n";
    return 0;
}