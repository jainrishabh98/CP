#include<bits/stdc++.h>
using namespace std;
vector <int> segtree;
vector <int> arr;
int level = 0;
int qlow, qhigh, p, diff;
void build (int low, int high, int pos)
{
    if(low == high)
    {
        segtree[pos] = arr[low];
        level = 1;
        return ;
    }
    int mid = (low+high)/2;
    build (low, mid, 2*pos + 1);
    build (mid+1, high, 2*pos + 2);
    if(level==1)
        {segtree[pos] = segtree[2*pos + 1] | segtree[2*pos + 2];level=0;}
    else
        {segtree[pos] = segtree[2*pos + 1] ^ segtree[2*pos + 2];level=1;}
}
void update(int low, int high, int pos)
{
    if(p<low || p>high)
        return ;
    if(low==high)
        {segtree[pos] = arr[p];level=1;}
    else
    {
        int mid = (low + high)/2;
        update(low,mid,2*pos + 1);
        update(mid+1,high,2*pos + 2);
        if(level==1)
        {segtree[pos] = segtree[2*pos + 1] | segtree[2*pos + 2];level=0;}
        else
        {segtree[pos] = segtree[2*pos + 1] ^ segtree[2*pos + 2];level=1;}
    }
}
int main ()
{
    int n;int q;
    cin>>n>>q;
    n = pow(2,n);
    arr.assign(n,0);
    int temp = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2,temp) -1;
    segtree.assign(max_size,0);
    for (int i=0; i<n; i++)
        cin>>arr[i];
    build(0,n-1,0);    
    while(q--)
    {
            int value;
            cin>>p>>value;
            p--;
            // diff = value ^ arr[p];
            arr[p] = value;
            update(0,n-1,0);
            cout<<segtree[0]<<"\n";
    }
    return 0;
}
