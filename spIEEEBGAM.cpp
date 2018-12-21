#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        double n;
        cin>>n;
        double ans = 1 - (1/(n+1));
        cout<<fixed;
        cout<<setprecision(8)<<ans<<"\n";
    }
    return 0;
}