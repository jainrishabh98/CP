#include<bits/stdc++.h>
using namespace std;
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string s;
        int cnt[26]={0};
        int vis[26]={0};
        for(int i=0;i<n;i++)
        {
            cin>>s;
            int l = s.length();
            for(int j=0;j<l;j++)
            {
                if(vis[s[j]-'a']==0)
                {
                    cnt[s[j]-'a']++;
                    vis[s[j]-'a'] = 1;
                }
            }
            memset(vis,0,sizeof(vis));
        }
        int ans = 0;
        for(int i=0;i<26;i++)
        {
            if(cnt[i]==n)
                ans++;
        }
        cout<<ans<<"\n";
    }
}