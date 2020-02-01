#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,k;
        cin>>n>>k;
        long long en[n+1],prefix[n+1];int ans[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>en[i];
            ans[i] = 0;
        }
        sort(en+1,en+n+1);
        prefix[0] = 0;
        prefix[1] = en[1];
        for(int i=2;i<=n;i++)
        {
            prefix[i] = en[i] + prefix[i-1];
        }
        for(int i=1;i<=n;i++)
        {
            int low=1,high = n,mid;
            while(low <=high)
            {
                mid = (low+high)/2;
                if(mid > i)
                {
                    if(prefix[mid-1]-(mid)*k > en[mid])
                    {
                        ans[i] = max(ans[i],mid);
                        low = mid+1;
                    }
                    else
                    {
                        high = mid -1;
                    }
                    
                }
                else if(mid < i)
                {
                    if(en[i]+prefix[mid-1]-(mid)*k > en[mid])
                    {
                        ans[i] = max(ans[i],mid);;
                        low = mid+1;
                    }
                    else
                    {
                        high = mid -1;
                    }
                    
                }
                
            }
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}