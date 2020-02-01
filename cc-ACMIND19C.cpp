#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ll b[k];
        ll sum = 0;
        ll prev = -1;
        int cnt = 0;
        for(int i=0;i<n-1;i++)
        {
            sum += a[i];
            if(sum>0)
            {
                while(sum+a[i+1] > 0 && a[i+1] <= 0)
                {
                    sum += a[i+1];
                    i++;
                    if(i==n-1)
                        break;
                }
                b[cnt] = i - prev;
                prev = i;
                sum = 0;
                cnt++;
                if(cnt==k-1)
                    break;
            }
        }
        if(cnt!=k-1)
        {
            cout<<"NO\n";
        }
        else
        {
            sum = 0;
            for(int i=prev+1;i<n;i++)
            {
                sum += a[i];
            }
            if(sum <=0)
            {
                cout<<"NO\n";
            }
            else
            {
                cout<<"YES\n";
                b[cnt] = n-1-prev;
                for(int i=0;i<=cnt;i++)
                {
                    cout<<b[i]<<" ";
                }
                cout<<"\n";
            }
        }
    }
}