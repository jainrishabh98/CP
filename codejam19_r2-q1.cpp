#include<bits/stdc++.h>
using namespace std;
struct st{
    long long int a,b;
};
bool comp(st x,st y)
{
    return (x.a == y.a) ? (x.b < y.b) : (x.a < y.a);
}
bool comp2(st x,st y)
{
    return (x.b == y.b) ? (x.a < y.a) : (x.b < y.b);
}
int main ()
{
    int t;
    cin>>t;
    for(int l=1;l<=t;l++)
    {
        int n;
        cin>>n;
        st s[n];
        for(int i=0;i<n;i++)
        {
            cin>>s[i].a>>s[i].b;
        }
        sort(s,s+n,comp);
        long long int ans = 0,m=1;
        for(int i=1;i<n;i++)
        {
            if(s[i].a-s[i-1].a>=1)
            {
                m = max(m,(s[i-1].b-s[i].b)/(s[i].a-s[i-1].a));
            }
        }
        ans += m;
        st cc[n];
        for(int i=0;i<n;i++)
        {
            cc[i].a = s[i].a;
            cc[i].b= s[i].b;
        }
        sort(s,s+n,comp2);
        int fl=0;
        if(m==1)
        {
            for(int i=0;i<n;i++)
            {
                if(cc[i].a!=s[i].a || cc[i].b!=s[i].b)
                {
                    fl=1;break;
                }
            }
            if(fl==0)
                cout<<"Case #"<<l<<": "<<ans<<"\n";
        }
        if(fl==1)
        {
        m=1;
        for(int i=1;i<n;i++)
        {
            if(s[i].b-s[i-1].b>=1)
            {
                m = max(m,(s[i-1].a-s[i].a)/(s[i].b-s[i-1].b));
            }
        }
        ans += m;
        cout<<"Case #"<<l<<": "<<ans<<"\n";
        }
    }
}