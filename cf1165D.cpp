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
        int n;
        cin>>n;
        long long int d[n];
        for(int i=0;i<n;i++)
            cin>>d[i];
        sort(d,d+n);
        long long int ans = d[n-1]*d[0];
        set <int> dd;
        for(long long int i=2;i*i<=ans;i++)
        {
            if(ans%i==0)
            {
                dd.insert(i);
                dd.insert(ans/i);
            }
        }
        if(dd.size()!=n)
        {
            cout<<-1<<"\n";
            continue;
        }
        int flag=0;
        int cnt=0;
        for(auto i:dd)
        {
            if(i!=d[cnt])
            {
                flag=1;
                break;
            }
            cnt++;
        }
        if(flag==1)
            cout<<-1<<"\n";
        else
            cout<<ans<<"\n";
    }
    
}