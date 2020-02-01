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
        int n,m,x;
        cin>>n;
        int cno =0, cne = 0,cnno = 0,cnne = 0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x%2==0)
                cne++;
            else
                cno++;
        }
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>x;
            if(x%2==0)
                cnne++;
            else
                cnno++;
        }
        cout<<(long long)(cnno)*cno + cnne*(long long)cne<<"\n";
    }
}