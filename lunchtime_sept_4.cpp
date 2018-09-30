#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        int a[n+1],b[n+1];
        int cnt=0;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            {cin>>b[i];
            if(b[i]==a[i])
                cnt++;
            }
        int x,y,z,l,r,c;
        while(q--)
        {
            cin>>x>>y>>z;
            l=x^cnt;r=y^cnt;c=z^cnt;
            cnt=0;
            //cout<<l<<r<<c;
            for(int i=l;i<=r;i++)
            {
                a[i]=c;
            }
            for(int i=1;i<=n;i++)
            {
                if(a[i]==b[i])
                    cnt++;
            }
            cout<<cnt<<"\n";
        }
    }
    return 0;
}
