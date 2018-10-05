#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long int t,p1,p2,k,q;
    cin>>t;
    while(t--)
    {
        cin>>p1>>p2>>k;
        q = (p1+p2)/k;
        if(q%2==0)
        {
            cout<<"CHEF\n";
        }
        else
        {
            cout<<"COOK\n";
        }
    }
    return 0;
}