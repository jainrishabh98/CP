#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll n,m,k,p;
    cin>>n>>m>>k>>p;
    ll x;
    ll sumr[n]={0};
    ll sumc[m]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>x;
            sumr[i] += x;
            sumc[j] += x; 
        }
    }
    priority_queue <ll> r;
    priority_queue <ll> c;
    for(int i=0;i<n;i++)
    {   
        // cout<<sumr[i]<<" ";
        r.push(sumr[i]);
    }
    // cout<<"\n";
    for(int i=0;i<m;i++)
    {   
        // cout<<sumc[i]<<" ";
        c.push(sumc[i]);
    }
    // cout<<"\n";
    ll ans = -1e18,val1,val2;
    ll ansr[k+1]={0};
    ll ansc[k+1]={0};
    for(int i=1;i<=k;i++)
    {
        val1 = r.top();r.pop();
        val2 = c.top();c.pop();
        ansr[i] = ansr[i-1] + val1;
        ansc[i] = ansc[i-1] + val2;
        r.push(val1 - (m*p));c.push(val2 - (n*p));
    }
    for(int i=0;i<=k;i++)
    {
        ans = max(ans,ansr[i]+ansc[k-i]-i*(k-i)*p);
    }
    cout<<ans;
}