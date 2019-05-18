#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int k[n+1];
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        sum += k[i];
    }
    int d[m],t[m];
    for(int i=0;i<m;i++)
    {
        cin>>d[i]>>t[i];
    }
    int low=1,high = 2*sum,mid;
    int ans = high;
    pair<int,int> tt[n+1];
    while(low <= high)
    {
        mid = (low+high)/2;
        for(int i=1;i<=n;i++)
        {
            tt[i].second = i;
            tt[i].first = 0;
        }
        for(int i=0;i<m;i++)
        {
            if(d[i] <= mid)
            {
                tt[t[i]].first = max(tt[t[i]].first,d[i]);
            }
        }
        sort(tt+1,tt+n+1);
        int taken=0;
        for(int i=1;i<=n;i++)
        {
            taken += min(tt[i].first-taken,k[tt[i].second]);
        }
        if(mid >= taken + (sum-taken)*2)
        {
            ans = mid;
            high = mid-1;
        }
        else
            low = mid + 1;
    }
    cout<<ans;
    
}