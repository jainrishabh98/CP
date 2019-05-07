#include<bits/stdc++.h>
using namespace std;
map <int,int> mp;
long long int cnt = 0;
void dfs(int u)
{
    mp[u] = 1;
    cnt++;
    u = u+1;
    while(u%10==0)
    {
        u/=10;
    }
    if(mp.find(u)==mp.end())
    {
        dfs(u);
    }
}
int main ()
{
    int n;
    cin>>n;
    dfs(n);
    cout<<cnt;
}