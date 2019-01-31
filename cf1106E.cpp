#include<bits/stdc++.h>
using namespace std;
struct st{  int s,t,d;
long long int w;

};
bool comp (st a, st b)
{
    if(a.s < b.s)
        return true;
    else if(a.s==b.s)
    {
        if(a.w > b.w)
            return true;
        else if(a.w==b.w)
        {
            if(a.d > b.d)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else return false;
    }
    else return false;
}
int main ()
{
    int n,m,k;
    cin>>n>>m>>k;
    st a[k];
    for(int i=0;i<k;i++)
    {
        cin>>a[i].s>>a[i].t>>a[i].d>>a[i].w;
    }
    sort(a,a+k,comp);
    vector <st> incl;
    // incl.push_back(a[0]);
    int len=-1;int ind=0;
    while(ind<k)
    {   
        incl.push_back(a[ind]);
        len++;
        ind = k;
        int low = 0,high=k-1,mid;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(a[mid].s >= incl[len].d+1)
            {
                ind = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
    }
    
}