#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m = 998244353;
ll fp(ll x,ll y)
{
    if(y==0)    return 1;
    else if(y==1) return x;
    else if(y%2==0) return (fp(x,y/2)*fp(x,y/2))%m;
    else return (((fp(x,y/2)*fp(x,y/2))%m)*x)%m;
}
int main ()
{
    int n;
    cin>>n;
    ll a[n];
    map <ll,pair<int,int> > mp;
    for(int i=0;i<n;i++)
        {cin>>a[i];
        if(mp.find(a[i])==mp.end()){
            mp[a[i]].first = i;
            mp[a[i]].second = i;
        }
        else
        {
            mp[a[i]].second=i;
        }
        }
    int pos = mp[a[0]].second;
    int i=0;ll l=0;
    while(i<n)
    {
    for(;i<=pos;i++)
    {
        if(mp[a[i]].second>pos) pos = mp[a[i]].second;
    }
    l++;
    pos = mp[a[i]].second;
    }
    cout<<fp(2,l-1);
}