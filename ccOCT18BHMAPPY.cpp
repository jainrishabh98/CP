#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
struct st{
    ull a;
    ull b;
    ull p;
};
bool comp (st c, st d)
{
    return(c.p<d.p);
}
int main ()
{
    ull n,m,temp;
    cin>>n>>m;
    st s[n];
    
    for (ull i =0; i<n;i++)
        cin>>s[i].a;
    for (ull i =0; i<n;i++)
        {cin>>s[i].b;
         s[i].p = s[i].a*s[i].b;
        }
    sort(s,s+n,comp);
    
    for (ull i =0; i<n;i++)
        cout<<s[i].p<<" ";
    ull i= n-1;
    while (m!=0 && i>=1)
    {   temp = m;
        m = m - ceil((s[i].p-s[0].p)/(float)(s[i].b));
        if(m<0)
            m=0;
        if(m!=0)
            s[i].p = s[i].p - ceil((s[i].p-s[0].p)/(float)(s[i].b))*(s[i].b);
        else
            s[i].p = s[i].p - temp*(s[i].b);
        if(s[i].p<0)
            s[i].p=0;
        i--;
    }
    sort(s,s+n,comp);
    cout<<s[n-1].p<<"\n";
    return 0;
}