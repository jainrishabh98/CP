#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{   int n;
    cin>>n;
    ll a[n];
    ll total = 0;
    for(int i=0;i<n;i++)
        {cin>>a[i];total +=a[i];}
    if(total%3!=0 || n<3)
        cout<<"0";
    else
    {
        ll req = total/3;
        ll sum =0;
        ll ans = 0;
        int l=-1,k=-1;
        vector <int> v1,v2;
        for(int i=0;i<n;i++)
        {
            sum += a[i];
            if(sum==req && l==-1)
            {
                l=i;
                sum =0;
            }
            else if(sum==req && k==-1)
            {
                k = i;
                break;
            }
        }
        if(l==-1 || k==-1)
        {
            cout<<"0";return 0;
        }
        v1.push_back(l);
        sum = 0;
        for(int i=l+1;i<n-2;i++)
        {
            sum += a[i];
            if(sum==0)
            {
                v1.push_back(i);
            }
        }
        v2.push_back(k);
        sum = 0;
        for(int i=k+1;i<n-1;i++)
        {
            sum += a[i];
            if(sum==0)
            {
                v2.push_back(i);
            }
        }
        ll temp = v2.size();
        for(auto i:v1)
        {
            ll ind = upper_bound(v2.begin(),v2.end(),i) - v2.begin();
            ans += (temp - ind);
        }
        cout<<ans;
    }
}