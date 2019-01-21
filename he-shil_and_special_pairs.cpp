#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n;
int tree[100001];
ll query(int k)
{
    ll sum=0;
    while(k>=1)
    {
        sum += tree[k];
        k -= (k&(-k));
    }
    return sum;
}
void update(int k,int x)
{
     while(k<=n)
    {
        tree[k] += x;
        k += (k&(-k));
    }
}
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    int m,d;
    cin>>n>>m>>d;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll cnt[n+1];
    for(int i=1;i<=n;i++)
    {
        int y = min(i+d,n);
        cnt[i] = y - i + 1;
    }
    for(int i=0;i<n;i++)
    {
        update(a[i],cnt[a[i]]);
    }
    ll res[n+1]={0};
    for(int i=n-1;i>=0;i--)
    {
        res[i+1] = query(n);
        update(a[i],-cnt[a[i]]);
        for(int j=a[i]-1;j>=max(1,a[i]-d);j--)
        {   
            if(cnt[j]!=0)
                { update(j,-1); cnt[j]--;}
        }
        cnt[a[i]]=0;
    }
    int l,r;
    while(m--)
    {
        cin>>l>>r;
        cout<<res[r]-res[l-1]<<"\n";
    }
    for(int i=1;i<=n;i++)
        cout<<res[i]<<" ";
}