#include<bits/stdc++.h>
using namespace std;
vector <int> segtree;
int p, diff;
int update(int low, int high, int pos)
{
    if(p<low || p>high)
        return segtree[pos];
    
    if (low == high)
    {
        segtree[pos] = diff;
        return segtree[pos];
    }
    int mid = (low + high)/2;
    segtree[pos] = min(update(low,mid,2*pos + 1) , update(mid+1, high, 2*pos + 2));
    return segtree[pos];
}
int main ()
{
    int n,m;
    cin>>n>>m;

    int x[m];
    for(int i=0;i<m;i++)
        cin>>x[i];
    int temp = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2,temp) -1;
    segtree.assign(max_size,0);
    
    int c[n+1]={0};
    int fl=0;
    for(int i=0;i<m;i++)
    {
        c[x[i]]++;
        diff = c[x[i]];
        p = x[i]-1;
        update(0,n-1,0);
        if(segtree[0]-fl==1)
        {
            fl = segtree[0];
            cout<<"1";
        }
        else
            cout<<"0";
    }
    
    cout<<"\n";
    return 0;
}