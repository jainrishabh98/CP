#include<bits/stdc++.h>
using namespace std;
// range not given -> hence sum of all elements can exceed 1e18 also. hence take mod at every element bcuz of mod properties
int main ()
{   long long int t;
    cin>>t;
    while(t--)
    {
        unsigned long long int n,x,ans=0,i;
        cin>>n;
        for(i=0;i<n;i++)
           { cin>>x; ans = (ans + x)%n;}

        if (ans == 0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}