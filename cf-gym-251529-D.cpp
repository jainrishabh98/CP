#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
pair<ll,ll> a[200005];
vector <pair<ll,ll>> aa[2];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,l;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second = i+1;
        cin>>l;
        aa[l].push_back(a[i]);
    }
    sort(a,a+n);
    sort(aa[0].begin(),aa[0].end());
    sort(aa[1].begin(),aa[1].end());
    ll sum = 0,r = n;
    for(int i=n-1;i>=0;i--)
    {
        sum += a[i].first;
        if(sum >= m)
        {
            r = n - i;
            break;
        }
    }
    sum = 0;
    int cnt = 0;
    ll w;
    int i;
    for(i=aa[1].size()-1;i>=0;i--)
    {
        sum += aa[1][i].first;
        cnt++;
        if(cnt==r)
            break;
    }
    w = cnt;
    int j = aa[0].size()-1;
    if(cnt < r)
    {
        while(j>=0)
        {
            sum += aa[0][j].first;
            cnt++;
            j--;
            if(cnt==r)
                break;
        }
    }
    i = max(i,0);
    while(sum < m && i<aa[1].size() && j>=0)
    {
        sum += aa[0][j].first;
        sum -= aa[1][i].first;
        i++;
        j--;
        w--;
    }
    j++;
    cout<<r<<" "<<w<<"\n";
    for(;i<aa[1].size();i++)
    {
        cout<<aa[1][i].second<<" ";
    }
    for(;j<aa[0].size();j++)
    {
        cout<<aa[0][j].second<<" ";
    }
}