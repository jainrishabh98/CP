#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ll k;
        cin>>k;
        while(k%2==0)
        {
            k /= 2 ;
        }
        cout<<"Case "<<i<<": "<<k<<"\n";
    }
    return 0;
}