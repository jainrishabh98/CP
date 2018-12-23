#include<bits/stdc++.h>
using namespace std;
int main ()
{   int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int flag=0;
        for(int i=n-2;i>=0;i--)
        {
            a[i] = a[i] - a[i+1];
            if(a[i]<0)
            {
                flag=1;break;
            }
        }
        if(a[0] != 0)
            {
                flag=1;
            }
        if(flag==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";

    }
    return 0;
}