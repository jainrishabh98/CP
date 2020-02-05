#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int vis[26] = {0};
    int ans[n];
    int res = 1;
    for(int i=0;i<n;i++)
    {
        int p = s[i] - 'a';
        int cnt = 1;
        for(int j=25;j>p;j--)
        {
            cnt = max(vis[j]+1,cnt);
        }
        ans[i] = cnt;
        res = max(res,cnt);
        vis[p] = max(vis[p],cnt);
    }
    cout<<res<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}