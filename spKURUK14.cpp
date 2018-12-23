#include<bits/stdc++.h>
using namespace std;
int main ()
{   int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n]={0};
        int x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x<n)
            {
                a[x]++;
            }

        }
        int flag = 0;
        for(int i=0;i<(n/2);i++)
        {
            if((a[i] + a[n-i-1]) != 2)
            {
                flag=1;break;
            }

        }
        if(n%2 ==1 && a[n/2]!=1)    flag=1;
        if(flag==1)
            cout<<"NO\n";
        else
            cout<<"YES\n";

    }
    return 0;
}