#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,p;
        cin>>n;
        p = n;
        vector <ll> v;
        while(n!=0)
        {
            v.push_back(n%10);
            n /= 10;
        }
        reverse(v.begin(),v.end());
        ll ans = p;
        int l = v.size();
        for(int i=0;i<l;i++)
        {
            ll temp = 0;
            for(int j=0;j<l;j++)
            {
                if(j==i)
                    continue;
                temp = temp*10 + v[j];
            }
            ans = min(ans,temp);
        }
        cout<<ans<<"\n";
    }

}