#include<bits/stdc++.h>
using namespace std;
vector <int> segtree;
vector <int> arr;
int l,r;
int INF = INT_MAX;
void build (int low, int high, int pos)
{
    if(low == high)
    {
        segtree[pos] = arr[low];
        // cout<<segtree[pos];
        return ;
    }
    int mid = (low+high)/2;
    build (low, mid, 2*pos + 1);
    build (mid+1, high, 2*pos + 2);
    if (low==mid && mid+1 == high)
    {
        if(segtree[2*pos + 2] >= segtree[2*pos + 1] )
            segtree[pos] = 2;
        else
            segtree[pos] = 1;
    }
    else if (mid+1 == high)
    {   int t = 2*pos + 1;
        if(segtree[t+1] >= segtree[2*t + 2])
            segtree[pos] = segtree[t] + 1;
        else 
            segtree[pos] = segtree[t];
    }
    else
    {   int c=0;
        int t = 2*pos + 1;
        if(segtree[t] ==2 &&  segtree[t+1] ==2 )
        {
            if(segtree[2*t + 2] ==1 && segtree[2*(t+1) + 1]==0)
                c=1;
        }
        segtree[pos] = segtree[t] + segtree[t+1] - c;
    }
}
void update(int low, int high, int pos)
{
    if(l>high || r<low)
        return ;
    if (low == high)
    {
        segtree[pos]= segtree[pos]^1;
        // cout<<segtree[pos];
        return ;
    }
    int mid = (low + high)/2;
    update(low,mid,2*pos + 1);
    update(mid+1,high,2*pos + 2);
    if (low==mid && mid+1 == high)
    {
        if(segtree[2*pos + 2] >= segtree[2*pos + 1])
            segtree[pos] = 2;
        else
            segtree[pos] = 1;
    }
    else if (mid+1 == high)
    {   int t = 2*pos + 1;
        if(segtree[t+1] >= segtree[2*t + 2])
            segtree[pos] = segtree[t] + 1;
        else 
            segtree[pos] = segtree[t];
    }
    else
    {   int c=0;
        int t = 2*pos + 1;
        if(segtree[t] ==2 &&  segtree[t+1] ==2 )
        {
            if(segtree[2*t + 2] ==1 && segtree[2*(t+1) + 1]==0)
                c=1;
        }
        segtree[pos] = segtree[t] + segtree[t+1] - c;
    }
    
}

int main ()
{
    int n,q;
    cin>>n>>q;
    string str;
    cin>>str;
    arr.assign(n,0);
    int temp = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2,temp) -1;
    segtree.assign(max_size,0);
    for (int i=0; i<str.length(); i++)
        arr[i] = str[i] - '0';
        
    build(0,n-1,0);    
    while(q--)
    {
        int x;
        cin>>x;
        if(x==1)
            cout<<segtree[0]<<"\n";
        else
        {
            cin>>l>>r;
            l--;r--;
            update(0,n-1,0);
            
        }
    }
    
    
    return 0;
}
