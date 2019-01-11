#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long int l,r,c,ans=0,f=1;
    cin>>l>>r;
    c = l^r;
    while(c!=0)
    {
        c /= 2;
        ans += f;
        f *= 2;
    }
    cout<<ans<<"\n";
    return 0;
}