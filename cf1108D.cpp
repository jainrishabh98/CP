#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int dp[n][3];
    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    if(s[0]=='B')
       dp[0][0] = 0;
    else if(s[0]=='G')
       dp[0][1] = 0;
    else if(s[0]=='R')
       dp[0][2] = 0;
    // vector <int> v[3];
    for(int i=1;i<n;i++)
    {
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + (s[i]=='B' ? 0 : 1) ;
        dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + (s[i]=='G' ? 0 : 1) ;
        dp[i][2] = min(dp[i-1][1],dp[i-1][0]) + (s[i]=='R' ? 0 : 1) ;
    }
    int ans = min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
    string res;
    if(ans==dp[n-1][0])
        res.push_back('B');
    else if(ans==dp[n-1][1])
        res.push_back('G');
    else if(ans==dp[n-1][02])
        res.push_back('R');
    int cnt = 0;
    for(int i=n-2;i>=0;i--)
    {
        if(res[cnt]=='B')
        {
            int x= dp[i+1][0];
            if(s[i+1]!='B') x--;
            if(dp[i][1]==x) res.push_back('G');
            else    res.push_back('R');
        }
        else if(res[cnt]=='G')
        {
            int x= dp[i+1][1];
            if(s[i+1]!='G') x--;
            if(dp[i][0]==x) res.push_back('B');
            else    res.push_back('R');
        }
        else if(res[cnt]=='R')
        {
            int x= dp[i+1][2];
            if(s[i+1]!='R') x--;
            if(dp[i][1]==x) res.push_back('G');
            else    res.push_back('B');
        }
        cnt++;
    }
    cout<<ans<<"\n";
    for(int i=res.size()-1;i>=0;i--)
    {
        cout<<res[i];
    }
}