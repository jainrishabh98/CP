#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool comp(int x,int y)
{
    return (x>y);
}
int main () 
{   ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k,x;
    cin>>n>>k;
    ll a[n];
    for(int i=0;i<n;i++)    cin>>a[i];
    string s;
    cin>>s;
    int cnt=0;
    ll sum =0;
    int i=0,j=0;
    vector <pair<int,int> > v;
    while(j<n)
    {
        while(s[j]==s[i] && j<n)
        {
            j++;
        }
        if(j-i<=k)
        {
            for(int b=i;b<j;b++)
                sum += a[b];
        }
        else
        {
            v.push_back(make_pair(i,j));
        }
        i=j;
    }
    for(auto h:v)
    {
        int x = h.first;
        int y = h.second;
        sort(a+x,a+y,comp);
        int cnt = 0;
        while(cnt<k)
        {
            sum += a[x];
            x++;
            cnt++;
        }
    }
    cout<<sum;
    
}