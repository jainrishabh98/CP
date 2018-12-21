#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(a[i] > i)
                {
                    flag=1;break;
                }            
            
        }   
        if(flag==1)
            cout<<"NO\n";
        else
            cout<<"YES\n";    
    }
    return 0;
}