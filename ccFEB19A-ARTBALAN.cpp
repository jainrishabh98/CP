#include<bits/stdc++.h>
using namespace std;
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    int t,sum,n,ans,tm;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        vector <int> v;
        int cnt[26]={0};
        sum = s.length();
        for(int i=0;i<s.length();i++)
        {
            cnt[s[i]-'A']++;
        }
        for(int i=0;i<26;i++)
        {
            if(cnt[i]!=0)
                v.push_back(cnt[i]);
        }
        sort(v.begin(),v.end());
        n = v.size();
        ans = 1e9;
        tm = 0;
        for(int i=0;i<n;i++)
        {   
            if(i>0) tm += v[i-1];
            if(sum%(n-i)==0)
            {
                int mean = sum/(n-i);
                int temp = 0;
                for(int j=i;j<n;j++)
                {
                    if(v[j] > mean)
                        temp += v[j] - mean;
                }
                temp += tm;
                // cout<<temp<<" "<<n-i<<"\n";
                ans = min(ans,temp);
            }
        }
        cout<<ans<<"\n";
    }
}