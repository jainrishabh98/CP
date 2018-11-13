#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n],b[n],flag=0;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            {cin>>b[i];
             if(a[i] - b[i] < 0)
                flag=1;
            }
        if(flag==1)
            {
                cout<<"-1\n";
                continue;
            }
        
    }
    return 0;
}