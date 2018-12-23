#include<bits/stdc++.h>
using namespace std;
int main ()
{   
    int t;
    cin>>t;
    while(t--)
    {
        int x,a;
        cin>>x>>a;
        int n = a-x;
        int sum = n*(a+1);
        int sum2 = ((n-1)*n)/2;
        cout<<sum-sum2<<"\n";
    }
    return 0;
}