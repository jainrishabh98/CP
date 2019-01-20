#include<bits/stdc++.h>
using namespace std;
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans = 0,x=0,i,cn,cnt;
    // cout<<char(x+97);
    for( x = 0; x<26; x++)
    {   cn=0;
        // cout<<x<<"\n";
        for(i=0;i<n;i++)
        {   cnt=0;
            while(s[i]==char(x+97) && i<n && cnt!=k) 
            {
                i++;
                cnt++;
            }
            if(cnt>0) i--;
            // cout<<i<<" ";
            if(cnt==k)  cn++;
        }
        ans = max(ans,cn);
    }
    cout<<ans;
}