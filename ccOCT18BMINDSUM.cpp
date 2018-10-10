#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll minval;
ll minsteps;
struct node 
{ 
    ll val; 
    ll level; 
};
ll digsum(ll a)
{   ll sum = 0;
    while(a!=0)
    {
        sum+= a%10;
        a = a/10;
    }
    return sum;
}
void mincost(ll n, ll d) 
{   minval = 1e18;
    minsteps = 1e18;
     
    set<ll> vis; 

    queue<node> q; 
    node p = {n, 0}; 
    q.push(p); 
    //ll flag = 0;
    while (!q.empty()) 
    { 
        //flag++;
        node t = q.front(); 
        q.pop(); 

        if (t.val < minval) 
            {
                minval = t.val;
                minsteps = t.level;
            } 
 
        vis.insert(t.val);   
        if (vis.find(digsum(t.val)) == vis.end() || digsum(t.val)==t.val) 
        { 
            if(digsum(t.val)!=t.val)
            {
            p.val = digsum(t.val); 
            p.level = t.level+1; 
            q.push(p); 
            }
            p.val = t.val + d; 
            p.level = t.level+1; 
            q.push(p); 
        } 
    } 
} 
int main ()
{
    ll t,n,d;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        mincost(n,d);
        cout<<minval<<" "<<minsteps<<"\n";
    }
    return 0;
}