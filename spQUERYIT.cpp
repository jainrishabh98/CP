#include<bits/stdc++.h>
using namespace std;
int INF = INT_MAX;
struct st{
    int z_index = -INF;
    int o_index = INF;
    int first = 0;
    int second = 0;
};
vector <st> segtree;
vector <int> arr;
int l,r;

void build (int low, int high, int pos)
{
    if(low == high)
    {
        if(arr[low]==0)
            {segtree[pos].first++;
             segtree[pos].z_index = low;
            }
        else
            {segtree[pos].second++;
             segtree[pos].o_index = low;
            }
        return ;
    }
    int mid = (low+high)/2;
    build (low, mid, 2*pos + 1);
    build (mid+1, high, 2*pos + 2);
    int t = 2*pos + 1;
    segtree[pos].first = segtree[t].first + segtree[t+1].first ;
    segtree[pos].second = segtree[t].second + segtree[t+1].second ;
    segtree[pos].z_index = max(segtree[t].z_index,segtree[t+1].z_index);
    segtree[pos].o_index = min(segtree[t].o_index,segtree[t+1].o_index);   
}
void update(int low, int high, int pos)
{
    if(l>high || r<low)
        return ;
    if (low == high)
    {
        arr[low]= arr[low]^1;
        segtree[pos].first=0;
        segtree[pos].second=0;
        segtree[pos].o_index=INF;
        segtree[pos].z_index= -INF;
        if(arr[low]==0)
            {segtree[pos].first++;
            segtree[pos].z_index = low;
            }
        else
            {segtree[pos].second++;
             segtree[pos].o_index = low;
            }
        return ;
    }
    int mid = (low + high)/2;
    update(low,mid,2*pos + 1);
    update(mid+1,high,2*pos + 2);
    int t = 2*pos + 1;
    segtree[pos].first = segtree[t].first + segtree[t+1].first ;
    segtree[pos].second = segtree[t].second + segtree[t+1].second ;
    segtree[pos].z_index = max(segtree[t].z_index,segtree[t+1].z_index);
    segtree[pos].o_index = min(segtree[t].o_index,segtree[t+1].o_index);
  
}
st query(int low, int high, int pos, int qlow, int qhigh)
{
    if(qlow<= low && qhigh>= high) // total overlap
        return segtree[pos];
    if(qlow > high || qhigh < low) // no overlap
        {
            st te;return te;
        }
    int mid = (low+high)/2;
    st ans1 = query(low,mid,2*pos + 1,qlow,qhigh);
    st ans2 = query(mid+1, high, 2*pos + 2,qlow,qhigh);
    ans1.first += ans2.first;
    ans1.second += ans2.second;
    ans1.z_index = max(ans1.z_index,ans2.z_index);
    ans1.o_index = min(ans1.o_index,ans2.o_index);
    return ans1;
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
    segtree.resize(max_size);
    for (int i=0; i<str.length(); i++)
        arr[i] = str[i] - '0';
    
    
    build(0,n-1,0);
    
    // qlow = 0;
    // qhigh = n-1;
    // pair<int,int> ans = query(0,n-1,0);  
    int  final_ans;
    while(q--)
    {
        int x;
        cin>>x;
        if(x==1)
            {   int temp1 = (segtree[0].first + query(0,n-1,0,segtree[0].z_index+1,n-1).second);
                int temp2 = (segtree[0].second + query(0,n-1,0,0,segtree[0].o_index-1).first);
                final_ans = max(temp1,temp2);
                // cout<<segtree[0].z_index<<" "<<segtree[0].o_index<<" "<<temp1<<" "<<temp2<<" "<<"\n";
                cout<<final_ans<<"\n";
            }
        else
        {
            cin>>l>>r;
            l--;r--;
            update(0,n-1,0);   
        }
    }
    
    
    return 0;
}
