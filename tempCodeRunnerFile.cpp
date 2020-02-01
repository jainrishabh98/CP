#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,c;
        cin>>n>>m>>c;
        ll a[c];
        double x;
        for(int i=0;i<c;i++)
        {
            cin>>x;
            a[i] = ceil(x);
        }
        sort(a,a+c);
        reverse(a,a+c);
        ll xx = ceil((double)min(n,m)/(double)2.0);
        ll sum = 0,ans = -1;
        for(int i=0;i<c;i++)
        {
            sum += a[i];
            if(sum >= xx)   
            {
                ans = i+1;
                break;
            }
        }
        cout<<ans<<"\n";
    }
}