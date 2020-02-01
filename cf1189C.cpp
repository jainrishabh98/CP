#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int s[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    s[0]=0;
    for(int i=1;i<=n;i++)
    {
        s[i] += s[i-1];
    }
    int q,l,r;
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        cout<<(s[r]-s[l-1])/10<<"\n";
    }
    
}