#include<bits/stdc++.h>
using namespace std;
struct st{
    int a,b;
};
bool comp(st a, st b)
{
    return (a.a == b.a) ? (a.b < b.b) : (a.a < b.a);
}
int main ()
{
    int n;
    cin>>n;
    st s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i].a>>s[i].b;
    }
    sort(s,s+n,comp);
    int ans = s[0].b;
    for(int i=1;i<n;i++)
    {
        if(s[i].b >= ans)
         ans  = s[i].b;
        else
        {
            ans = s[i].a;
        }
    }
    cout<<ans;
}