#include<bits/stdc++.h>
using namespace std;
int main ()
{
    unsigned long long int n,x,y, mx =0, i;
    cin>>n;
    for (i = 0; i<n ;i++)
    {
        cin>>x>>y;
        mx = max(mx,x+y);
    }
    cout<<mx<<"\n";
    return 0;
}