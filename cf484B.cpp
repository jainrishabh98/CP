#include<bits/stdc++.h>
using namespace std;
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector <int> a;
    int x;
    map <int,int> mp;
    for(int i=0;i<n;i++)
        {cin>>x;
        if(mp.find(x)==mp.end())
        {
            a.push_back(x);
            mp[x]=1;
        }
        }
    sort(a.begin(),a.end());
    int mx = 0;
    n = a.size();
    for(int i=n-1;i>=0;i--)
    {   
         if(mx>=a[i]) break; // such conditions can be very imp. without this tle...with this AC
        int j = 2*a[i];
        auto index = lower_bound(a.begin(),a.end(),j) - a.begin();index--;
        int flag=0;
        while(index!=(n-1) || flag==0)
        {   if(index==n-1) flag=1;
            mx = max(mx,a[index]%a[i]);
            j+=a[i];
            index = lower_bound(a.begin(),a.end(),j) - a.begin();
            index--;
        }
    }
    cout<<mx<<"\n";
    return 0;
}