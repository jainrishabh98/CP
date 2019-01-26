#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n;
int segtree[400001];
int a[100001];
int qlow, qhigh, p, diff;
void build (int low, int high, int pos)
{
    if(low == high)
    {
        segtree[pos] = a[low];
        return ;
    }
    int mid = (low+high)/2;
    build (low, mid, 2*pos + 1);
    build (mid+1, high, 2*pos + 2);
    segtree[pos] = max(segtree[2*pos + 1] , segtree[2*pos + 2]);
}
void update(int low, int high, int pos)
{
    if(qlow > high || qhigh < low) // no overlap
        return ;
    if(low == high)
    {   
        a[low] += p;
        segtree[pos] = a[low];
        return ;
    }
    int mid = (low+high)/2;
    update (low, mid, 2*pos + 1);
    update (mid+1, high, 2*pos + 2);
    segtree[pos] = max(segtree[2*pos + 1] , segtree[2*pos + 2]);
}
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin>>n>>m;
    for(int i=0;i<n;i++)    cin>>a[i];
    int l[m],r[m];
    for(int i=0;i<m;i++)    
    {
        cin>>l[i]>>r[i];
        l[i]--;
        r[i]--;
    }
    int ans = 0,ansi=0,anc=0;
    int cnt=0;
    build(0,n-1,0);
    for(int i=0;i<n;i++)
    {   
        for(int j=0;j<m;j++)
        {   
            if(l[j]==i)
            {   
                qlow = i;qhigh = r[j];
                p = -1;
                update(0,n-1,0);
                cnt++;
        
            }
            if(r[j]==i-1)
            {    
                 qlow = l[j];qhigh=i-1;
                 p = 1;
                 update(0,n-1,0);
                 cnt--;
            }
        }
        int mn = a[i];
        int mx = segtree[0];
        if(mx-mn >= ans)
        {
            ans = mx-mn;
            ansi = i;
            anc = cnt;
        }
    }
    cout<<ans<<"\n"<<anc<<"\n";
    for(int i=0;i<m;i++)
    {
        if(ansi>=l[i] && ansi<=r[i])
        {
            cout<<i+1<<" ";
        }
    }

}
