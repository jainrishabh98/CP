#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int b,k;
    cin>>b>>k;
    if(b%2==0) b=0;
    else b=1;
    int ans=0;
    int x;
    for(int i=0;i<k-1;i++)
    {
        cin>>x;
        (ans += (x*b))%=2;
    }
    cin>>x;
    (ans += x)%=2;
    if(ans==0)
        cout<<"even";
    else
        cout<<"odd";
}