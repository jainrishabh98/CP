#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct st{
    ll val;
    ll ind;
};
bool comp (st a, st b)
{
    return (a.val==b.val) ? (a.ind < b.ind) : (a.val>b.val);
}
ll ftree[1000001] ={0};
ll n;
ll sum(ll k)
{
    ll s=0;
    while(k>=1)
    {
        s += ftree[k];
        k -= (k&(-k));
    }
    return s;
}
void update(ll k,ll x)
{
    while(k<=n)
    {
        ftree[k] += x;
        k += (k&(-k));
    }
}
int main ()
{
    ll k;
    cin>>n>>k;
    st a[n];
    for(int i=0;i<n;i++)    {cin>>a[i].val;a[i].ind=i+1;}
    sort(a,a+n,comp);
    ll f[n] = {0};
    for(int i=0;i<n;i++)
    {
        f[a[i].ind-1] = sum(n) - sum(a[i].ind);
        update(a[i].ind,1);
    }
    sort(f,f+n);
    int i=n-1,j=0;
    ll ans=0;
    while(i>=j)
    {
        while(f[i]+f[j]<k && i>=j)  j++;
        ans += max(0,i - j) ;
        i--;
    }
    cout<<ans;
}   