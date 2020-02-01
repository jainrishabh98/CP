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
        long double a[c];
        long double x;
        for(int i=0;i<c;i++)
        {
            cin>>a[i];
        }
        sort(a,a+c);
        reverse(a,a+c);
        long double xx = min(n,m);
        long double sum = 0;
        int ans = -1;
        // if(a[0] >= min((n+1)/2,(m+1)/2) - 1)
        // {
        //     cout<<1<<"\n";
        //     continue;
        // }
        for(int i=0;i<c;i++)
        {
            sum += 2.0*a[i];
            if(sum - xx >= 0)   
            {
                ans = i+1;
                break;
            }
        }
        cout<<ans<<"\n";
    }
}