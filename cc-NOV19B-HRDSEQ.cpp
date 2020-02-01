#include<bits/stdc++.h>
using namespace std;
int dp[129];
int main ()
{
    int seq[130];
    seq[1] = 0;seq[2] = 0;dp[1] = 1;
    for(int i=2;i<=128;i++)
    {
        int cnt = 0;
        seq[i+1] = 0;
        for(int j=i-1;j>=1;j--)
        {
            if(seq[j]==seq[i])
            {
                cnt++;
                if(cnt==1)
                    seq[i+1] = i-j;
            }
        }
        dp[i] = cnt+1;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;  
        cin>>n;
        cout<<dp[n]<<"\n";
    }
}