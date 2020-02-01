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
        int n,m;
        cin>>n>>m;
        int x,y,s;
        cin>>x>>y>>s;
        int prev = 0,in;
        long long s1 =0,s2 = 0;
        for(int i=0;i<x;i++)
        {
            cin>>in;
            s1 += ((in - prev - 1)/s);
            prev = in;
        }
        s1 += ((n - prev)/s);
        prev = 0;
        for(int i=0;i<y;i++)
        {
            cin>>in;
            s2 += ((in - prev - 1)/s);
            prev = in;
        }
        s2 += ((m - prev)/s);
        cout<<s1*s2<<"\n";
    }
}