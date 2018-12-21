#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans = -1;
        while(ans != 0)
        {
            ll sum = 0;
            ll temp = n;
            while(temp!=0)
            {
            sum += (temp%10);
            temp /= 10;
            }
            ans = n%sum;
            n++;
        }
        cout<<n-1<<"\n";
        
    }
    return 0;
}