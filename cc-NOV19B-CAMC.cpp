#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        pair<int,int> a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i].first;
            a[i].second = i%m;
        }
        map<int,int> mp;
        int ans = 1e9;
        sort(a,a+n);
        int i=0,j=1;
        mp[a[i].second]++;
        while(j<n)
        {
            while(mp.size() < m && j < n)
            {
                mp[a[j].second]++;
                j++;
            }
            if(j==n && mp.size() < m)
                break;
            while(mp.size() == m )
            {
                ans = min(ans,a[j-1].first - a[i].first);
                mp[a[i].second]--;
                if(mp[a[i].second]==0)
                    mp.erase(a[i].second);
                i++;
            }
        }
        cout<<ans<<"\n";
    }
}