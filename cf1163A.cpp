#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,m;
    cin>>n>>m;
    if(m==0)
        cout<<1;
    else if (m==n)
        cout<<0;
    else
    {
        if(m < ceil(n/2.0))
        {
            cout<<m;
        }
        else if(m == ceil(n/2.0))
        {
            cout<<n/2;
        }
        else
        {
            m -= ceil(n/2.0);
            cout<<n/2 - m;
        }
    }
}