#include<bits/stdc++.h>
using namespace std;
int  main ()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        if(x%2==0)
        {
        int ans = 0;
        while(x!=0)
        {
            int temp = x%2;
            ans = ans*2 + temp;
            x=x/2;
        }
        cout<<ans<<"\n";
        }
        else
            cout<<x<<"\n";
    }
    return 0;
}