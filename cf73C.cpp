#include<bits/stdc++.h>
using namespace std;
// couldn't do on own
/* It is easy to see that if we put some symbol c at position p of the string s it will not affect symbols at positions (p+2) 
and greater. So we have a standard DP problem. State of the dynamic is described by three parameters: p – the number of already
 processed symbols (or the index of currently processed symbol of the string), c – the previous symbol, t – the number of allowed
  symbol changes. To calculate the answer for a state we should choose the best value among all symbols for current position
   (when t > 0) or just go to the index (p + 1) with current symbol s[p]. Thus we get the followings formulas:

d[n][*][*] = 0

d[p][c][t] = d[p + 1][s[p]][t] + bonus[c][s[p]] when t = 0

d[p][c][t] = max(d[p + 1][c’][t – (c’ <> s[p])] + bonus[c][c’])

where n  is the length of string s.

Computation complexity of the algorithm is O(n * k * h^2), where h is the alphabet size (h = 26 for current problem).
*/

int main ()
{   string s;char x,y;
    int mp[27][27] = {0};
    int dp [101][27][101];
    cin>>s;
    int n,k,c;
    cin>>k>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y>>c;
        mp[x-96][y-96] = c;
    }
    int diff;
    for (int i=s.length();i>=0;i--)
    {
        for(int l=0;l<=k;l++)
        {   
            for(int j=1;j<=26;j++)
            {                      
                if(i==s.length())
                {
                    dp[i][j][l] = 0;
                }
                else if (l==0)
                {
                    dp[i][j][l] = dp[i+1][s[i]-96][l] + mp[j][s[i]-96];
                }
                else
                { dp[i][j][l] = INT_MIN;
                    for(int c=1;c<=26;c++)
                    {   if(c==s[i]) diff=0;
                        else diff=1;
                        dp[i][j][l] = max(dp[i][j][l], dp[i+1][c][l-diff] + mp[j][c]);
                    }
                }
                cout<<dp[i][j][l]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
   int ans = INT_MIN;
        for(int l=0;l<=k;l++)
        {
        for(int j=1;j<=26;j++)
        {
            ans = max(ans,dp[1][j][l]);
        }
        }
    cout<<ans<<"\n";
    return 0;
}