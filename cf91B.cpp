#include <bits/stdc++.h>
using namespace std;
int ans[100005];
int a[100005];
int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map <int,int> mp;
    for (int i = 0; i < n; i++)
        {cin >> a[i];
        mp[a[i]]=i;
        }
    set <int> s;
    int sz = 1;
    s.insert(a[n-1]);
    ans[n-1] = -1;
    for(int i=n-2;i>=0;i--)
    {
        if(a[i] == *s.begin())
            ans[i]=-1;
        else if(a[i] < *s.begin())
        {
            ans[i] = -1;
            s.insert(a[i]);
            sz++;
        }
        else
        {
            auto ind = s.lower_bound(a[i]);
            ind--;
            ans[i] = mp[*ind] - i -1;
        }
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
}