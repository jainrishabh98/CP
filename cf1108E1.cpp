#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n;
int tree[100005] = {0};
int query(int k)
{
    int s = 0;
    while(k>=1)
    {
        s += tree[k];
        k -= (k&(-k));
    }
    return s;
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
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++)    cin>>a[i];
    int l[m+1],r[m+1];
    for(int i=1;i<=m;i++)    
    {
        cin>>l[i]>>r[i];
    }
    int ans = 0,ansi=0,anc=0;
    for(int i=1;i<=n;i++)
    {   
        int cnt=0;
        int mx = INT_MIN;
        int mn = a[i];
        for(int j=1;j<=m;j++)
        {   
            if(i>=l[j] && i<=r[j])
            {
                update(l[j],1);
                update(r[j]+1,-1);
                cnt++;
                mn--;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            mx = max(mx,a[i]-query(i));
        }
        if(mx-mn > ans)
        {
            ans = mx-mn;
            ansi = i;
            anc = cnt;
        }
        for(int j=1;j<=m;j++)
        {
            if(i>=l[j] && i<=r[j])
            {
                update(l[j],-1);
                update(r[j]+1,1);
            }
        }
    }
    cout<<ans<<"\n"<<anc<<"\n";
    for(int i=1;i<=m;i++)
    {
        if(ansi>=l[i] && ansi<=r[i])
        {
            cout<<i<<" ";
        }
    }

}
