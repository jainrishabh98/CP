#include<bits/stdc++.h>
using namespace std;
int main ()
{   long long int t;
    cin>>t;
    while(t--)
    {
        unsigned long long int n,x,sum=0,i;
        cin>>n;
        for(i=0;i<n;i++)
           { cin>>x; sum += x;}
           
        if (sum%n == 0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}