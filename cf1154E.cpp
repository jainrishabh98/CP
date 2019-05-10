#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int a[n];
    map<int,int> mp;
    int fwd[n],bck[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]=i;
        fwd[i] = i+1;
        bck[i] = i-1;
    }
    int b[n];
    int p = 1;
    while(!mp.empty())
    {
        auto it = mp.end();
        it--;
        int l = it->second;
        int cnt = 0,i=fwd[l],j=bck[l];
        while(cnt!=k && i!=n )
        {
            b[i]=p;
            mp.erase(a[i]);
            i = fwd[i];
            cnt++;
        }
        cnt=0;
        while(cnt!=k && j!=-1 )
        {
            b[j]=p;
            mp.erase(a[j]);
            j = bck[j];
            cnt++;
        }
        b[l] = p;
        mp.erase(a[l]);
        // cout<<mp.size()<<"\n";
        if(i!=n)
        {
            bck[i] = j;
        }
        if(j!=-1)
        {
            fwd[j] = i;
        }
        p = p^3;
    }
    for(int i=0;i<n;i++)
    {
        cout<<b[i];
    }

}