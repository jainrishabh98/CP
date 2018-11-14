#include<bits/stdc++.h>
using namespace std;
struct st{
    int value;
    int in;
};
bool comp (st a, st b)
{
    return (a.value != b.value ? (a.value < b.value) : (a.in > b.in) );
}
vector <int> segtree;
vector <int> arr;
int qlow, qhigh, p, diff;
int INF = INT_MAX;
void build (int low, int high, int pos)
{
    if(low == high)
    {
        segtree[pos] = 0;
        return ;
    }
    int mid = (low+high)/2;
    build (low, mid, 2*pos + 1);
    build (mid+1, high, 2*pos + 2);
    segtree[pos] = 0;
}
void update(int low, int high, int pos)
{
    if(p<low || p>high)
        return ;
    if (low == high)
    {
        segtree[pos]=diff;
        return ;
    }
    int mid = (low + high)/2;
    update(low,mid,2*pos + 1);
    update(mid+1,high,2*pos + 2);
    segtree[pos] = max(segtree[2*pos + 1],segtree[2*pos + 2]);
}
int query(int low, int high, int pos)
{
    if(qlow<= low && qhigh>= high) // total overlap
        return segtree[pos];
    if(qlow > high || qhigh < low) // no overlap
        return -INF;
    int mid = (low+high)/2;
    return (max(query(low,mid,2*pos + 1),query(mid+1, high, 2*pos + 2)));
}
int main ()
{
    int n,t;
    cin>>t;
    while(t--)
    {
    cin>>n;
    arr.assign(n,0);
    st s[n];
    int temp = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2,temp) -1;
    segtree.assign(max_size,0);
    for (int i=0; i<n; i++)
        {cin>>arr[i];
        s[i].value=arr[i];
        s[i].in = i;
        }
    build(0,n-1,0);    
    int l;
    cin>>l;
    sort(s,s+n,comp);
    qlow = 0;
    int ans = INF;
    for (int i=0;i<n;i++)
    {   p = s[i].in;
        if (p>0)
        {
            qhigh =  p-1;
            diff = query(0,n-1,0) + 1;
        }
        else
            diff =1;
        // cout<<diff<<"\n";
        if (diff == l)
           ans = min(ans,s[i].value);
        update(0,n-1,0);
    }
    // for (int i=0;i<max_size;i++)
    //     cout<<segtree[i]<<" ";
    // cout<<"\n";
    if(segtree[0] < l)
        cout<<"-1\n";
    else
        cout<<ans<<"\n";
    
    }
    return 0;
}
