#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--)
    {
        int l1,l2,r1,r2;
        cin>>l1>>r1>>l2>>r2;
        if(l1!=r2)
        cout<<l1<<" "<<r2<<"\n";
        else 
        cout<<r1<<" "<<r2<<"\n";

    }
}