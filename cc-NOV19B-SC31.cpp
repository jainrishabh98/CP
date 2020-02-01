#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int cnt[10] = {0};
        string s;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            for(int j=0;j<s.length();j++)
            {
                cnt[j] += (s[j] - '0');
            }
        }
        int ans = 0;
        for(int i=0;i<10;i++)
        {
            if(cnt[i]&1)
            {
                ans++;
            }
        }
        cout<<ans<<"\n";
    }

}