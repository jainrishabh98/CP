#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll tree[1000005];
int n;
ll query(int k)
{
    ll s = 0;
    while(k>=1)
    {
        s += tree[k];
        k -= (k&(-k));
    }
    return s;
}
void update(int k,ll x)
{
    while(k<=n)
    {
        tree[k] += x;
        k += (k&(-k));
    }
}
int main ()
{
    int q;
    cin>>n>>q;
    string s1;
    int a,b;
    while(q--)
    {
        cin>>s1>>a>>b;
        if(s1[0]=='a')
        {
            update(a,b);
        }
        else
        {
            cout<<query(b) - query(a-1)<<"\n";
        }
    }
}