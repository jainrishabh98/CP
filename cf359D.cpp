#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)    cin>>a[i];
    int m = log2(n) + 1;
    int sparse[n][m];
    for(int j=0;j<m;j++)
    {   
        int temp = pow(2,j);
        for(int i=0;i<=n-temp;i++)
        {
            if(temp == 1)
            {
                sparse[i][j] = a[i];
            }
            else
            {
                sparse[i][j] = __gcd(sparse[i][j-1],sparse[i+temp/2][j-1]);
            }
        }
    }
    int mx=0,low,high,mid,l,k,ans,ll,rl;
    set <int> anss;
    for(int i=0;i<n;i++)
    {
        low = 0,high = i;
        while(low<high)
        {   
            mid = (low+high)/2;
            l = i - mid + 1;
            k = log2(l);
            ans = __gcd(sparse[mid][k],sparse[mid + l-(int)pow(2,k)][k]);
            if(ans!=a[i])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        ll = low;
        low = i,high = n-1;
        int as;
        while(low<=high)
        {   
            mid = (low+high)/2;
            l = mid - i + 1;
            k = log2(l);
            ans = __gcd(sparse[i][k],sparse[i + l-(int)pow(2,k)][k]);
            if(ans!=a[i])
            {
                high = mid - 1;
            }
            else
            {   
                as = mid;
                low = mid+1;
            }
        }
        rl = as;
        // cout<<ll<<" "<<rl<<"\n";
        if(rl - ll > mx)
        {
            mx = rl - ll;
            anss.clear();
            anss.insert(ll);
        }
        else if (mx == rl - ll)
        {
            anss.insert(ll);
        }
    }
    cout<<anss.size()<<" "<<mx<<"\n";
    for(auto i:anss)
        cout<<i+1<<" ";
}