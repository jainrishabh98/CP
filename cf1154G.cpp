#include<bits/stdc++.h>
using namespace std;
int mp[10000007];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    long long int res = 1e16,N=1e7+1;
    int ans[2];
    for(int gc=1;gc<min(res,N);gc++)
    {
        long long int gf=0,gs=0;
        for(int j=gc;j<min(res,N);j+=gc)
        {
            if(mp[j] && gf)
            {
                gs = j;
                break;
            }
            else if(mp[j])
            {
                gf = j;
                if(mp[j]>1)
                {
                    gs = j;
                    break;
                }
            }
        }
        if(((gf*gs)/gc) < res && gf!=0 && gs!=0)
        {
            res = (gf*gs)/gc;
            ans[0] = gf;
            ans[1] = gs;
        }
    }
    int fl1=-1,fl2=-1;
    // cout<<res<<" "<<ans[0]<<" "<<ans[1]<<"\n";
    for(int i=0;i<n;i++)
    {
        if(a[i]==ans[0] && fl1==-1)
        {
            fl1 = i+1;
        }
        else if(a[i]==ans[1] && fl2==-1)
        {
            fl2 = i+1;
        }
    }
    cout<<min(fl1,fl2)<<" "<<max(fl1,fl2);
}