#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,m;
    cin>>n>>m;
    int cnt[m][26]={0};
    long long int ans=1,num=0,mod = 1e9 + 7;
    string s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int j=0;j<m;j++)
    {   num = 0;
        for(int i=0;i<n;i++)
        {
            int x = s[i][j] - 'A';
            if(cnt[j][x]==0)    {cnt[j][x]=1;num++;}
        }
        (ans *= num)%=mod;
    }
    cout<<ans;
}