#include<bits/stdc++.h>
using namespace std;
vector <int> segtree;
vector <int> arr;
int qlow, qhigh, p, diff;
void build (int low, int high, int pos)
{
    if(low == high)
    {
        segtree[pos] = arr[low];
        return ;
    }
    int mid = (low+high)/2;
    build (low, mid, 2*pos + 1);
    build (mid+1, high, 2*pos + 2);
    segtree[pos] = segtree[2*pos + 1] + segtree[2*pos + 2];
}
void update(int low, int high, int pos)
{
    if(p<low || p>high)
        return ;
    segtree[pos] += diff;
    if (low != high)
    {
        int mid = (low + high)/2;
        update(low,mid,2*pos + 1);
        update(mid+1,high,2*pos + 2);
    }
}
int query(int low, int high, int pos)
{
    if(qlow<= low && qhigh>= high) // total overlap
        return segtree[pos];
    if(qlow > high || qhigh < low) // no overlap
        return 0;
    int mid = (low+high)/2;
    return (query(low,mid,2*pos + 1) + query(mid+1, high, 2*pos + 2));
}
int main ()
{
    int n;
    cin>>n;
    arr.assign(n,0);
    int temp = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2,temp) -1;
    segtree.assign(max_size,0);
    for (int i=0; i<n; i++)
        cin>>arr[i];
    build(0,n-1,0);    
    int q,x;
    cin>>q;
    while(q--)
    {
        cin>>x;
        if(x==1) // range sum query
        {
            cin>>qlow>>qhigh;
            int ans = query(0,n-1,0);
            cout<<ans<<"\n";
        }
        else // update 
        {   int value;
            cin>>p>>value;
            diff = value - arr[p];
            arr[p] = value;
            update(0,n-1,0);
        }
    }
}
