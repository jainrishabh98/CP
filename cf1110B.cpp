#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    ll b[n];
    for(int i=0;i<n;i++)    cin>>b[i];
    ll low=b[0];
    ll ans = 0,cnt=1;
    ll v[n]={0};
    v[0]=1;
    vector <int>vec;
    for(int i=1;i<n-1;i++)
    {
        if(b[i+1] - b[i] < b[i] - low)
        {
            low = b[i];
            cnt++;
            v[i]=1;
            vec.push_back(i);
        }
    }
    if(cnt<=k)
    {
    int h = n-1;
    for(;h>=0;h--)
    {
        if(cnt==k)
        {
            break;
        }
        if(v[h]!=1)
        {
            v[h]=1;
            cnt++;
        }
    }
    }
    else
    {
    int j = vec.size()-1,i=0;
    int hi = b[n-1];
    while(i<j)
    {
        if(cnt==k)
        {
            break;
        }
        if(b[vec[i+2]-1] - b[vec[i]] <= hi - b[vec[j-1]])
        {
            v[vec[i+1]]=0;
            cnt--;
            i+=2;
        }
        else
        {
            v[vec[i+1]]=0;
            cnt--;
            
        }
    }
    }
    for(int i=n-1;i>=0;i--)
    {   
        ll high = b[i];
        while(v[i]!=1)  i--;
        ans += (high - b[i] + 1);
    }
    cout<<ans;
}