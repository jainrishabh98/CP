#include<bits/stdc++.h>
using namespace std;
int cnt[200005];
int main ()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]--;
    }
    int k[m],sum=0,p=m;
    for(int i=0;i<m;i++)
    {
        cin>>k[i];
        sum += k[i];
        if(k[i]==0)
            p--;
    }
    int i=0,j=0,ans=n+1,cn=0;
    while(i<n && j<n)
    {
        while(j<n)
        {
            cnt[a[j]]++;
            if(cnt[a[j]]==k[a[j]])
                cn++;
            if(cn==p)
                break;
            j++;
        }
        if(j==n)
            break;
        while(cn==p)
        {
            ans = min(ans,j-i+1);
            cnt[a[i]]--;
            if(cnt[a[i]] < k[a[i]])
                cn--;
            i++;
        }
        j++;
    }
    if(ans==n+1)
        cout<<-1;
    else
        cout<<ans - sum;
    
}