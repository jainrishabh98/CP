#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,k,a,b;
int s[100005];
// # define mp make_pair
// queue <pair<int,int> > q;
ll ans = 0;
ll fun(ll u,ll v)
{
    // q.push(mp(i,j));
    // while(!q.empty())
    // {
    //     int u = q.front().first;
    //     int v = q.front().second;
    //     q.pop();
        ll temp = 0;
        ll m = (u+v)/2;
        ll ind1 = lower_bound(s,s+k,u) - s;
        ll ind2 = upper_bound(s,s+k,m) - s;
        ll ind3 = lower_bound(s,s+k,m+1) - s;
        ll ind4 = upper_bound(s,s+k,v) - s;
        // cout<<u<<" "<<v<<" "<<ind1<<" "<<ind2<<" "<<ind3<<" "<<ind4<<"\n";
        ll num = (b*(ind4 - ind1)*(v-u+1));
        if(v==u)
        {
            temp =  num;
            
        }
        else if(ind2 - ind1 == 0)
        {
                temp = min(num,a+fun(m+1,v));
                
        }
        else if(ind4 - ind3 == 0)
        {
                temp = min(num,a+fun(u,m));
        }
        else
        {
            temp = min(num,fun(u,m)+fun(m+1,v));
        }
        return temp;

    // }
}
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k>>a>>b;
    for(int i=0;i<k;i++)    cin>>s[i];
    sort(s,s+k);
    ans = fun(1,pow(2,n));
    cout<<ans;
}