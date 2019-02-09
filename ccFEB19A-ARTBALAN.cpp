#include<bits/stdc++.h>
using namespace std;
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    int t,sum,ans,tm;
    int cnt[26];
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        memset(cnt,0,sizeof(cnt));
        sum = s.length();
        for(int i=0;i<s.length();i++)
        {
            cnt[s[i]-'A']++;
        }
        sort(cnt,cnt+26);
        ans = 1e9;
        tm = 0;
        for(int i=0;i<26;i++)
        {   
            if(i>0) tm += cnt[i-1];
            if(sum%(26-i)==0)
            {
                int mean = sum/(26-i);
                int temp = 0;
                for(int j=i;j<26;j++)
                {
                    if(cnt[j] > mean)
                        temp += cnt[j] - mean;
                }
                temp += tm;
                // cout<<temp<<" "<<n-i<<"\n";
                ans = min(ans,temp);
            }
        }
        cout<<ans<<"\n";
    }
}