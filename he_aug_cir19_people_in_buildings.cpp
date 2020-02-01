#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,g;
    cin>>n>>g;
    pair<ll,int> p[n];
    ll x,y;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        p[i].first = x*x + y*y;
        p[i].second = i+1;
    }
    sort(p,p+n);
    int cnt = 0;
    int rem = n;
    vector <int> s[n]; 
    for(int i=0;i<n;)
    {
        if(rem < g+g)
        {
            s[cnt].push_back(p[i].second);
            rem--;
            i++;
        }
        else
        {
            for(int j=i;j<i+g;j++)
            {
                s[cnt].push_back(p[j].second);
            }
            cnt++;
            i += g;
            rem -= g;
        }
    }
    cnt++;
    cout<<cnt<<"\n";
    for(int i=0;i<cnt;i++)
    {
        cout<<s[i].size()<<"\n";
        for(auto j:s[i])
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}