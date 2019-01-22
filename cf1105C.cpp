#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m = 1e9 + 7;
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,l,r,a,b,c;
    cin>>n>>l>>r;
    a = b = c = (r/3) - ((l-1)/3);
    if(r%3==1) b++;  else if(r%3==2) {c++;b++;}
    if((l-1)%3==1) b--;  else if((l-1)%3==2) {c--;b--;}
    ll dp[n+1][3];
    dp[1][0]=a;dp[1][1]=b;dp[1][2]=c;
    for(int i=2;i<=n;i++)
    {
        dp[i][0] = ((dp[i-1][0]*a)%m + (dp[i-1][1]*c)%m + (dp[i-1][2]*b)%m)%m;
        dp[i][1] = ((dp[i-1][0]*b)%m + (dp[i-1][1]*a)%m + (dp[i-1][2]*c)%m)%m;
        dp[i][2] = ((dp[i-1][0]*c)%m + (dp[i-1][1]*b)%m + (dp[i-1][2]*a)%m)%m;
    }
    cout<<dp[n][0];
}