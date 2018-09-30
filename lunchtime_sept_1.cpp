#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int s[n],j[n];
        int c=0;

        for (int i=0;i<n;i++)
        {
            cin>>s[i];
            cin>>j[i];
            if((j[i]-s[i])>5)
                c++;
        }
        cout<<c<<"\n";

    }
    
    return 0;
}