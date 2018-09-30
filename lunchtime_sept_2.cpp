#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {   int n,m;
        cin>>n>>m;
        int l[n],r[n],p[m];
        for (int i=0;i<n;i++)
        {
            cin>>l[i]>>r[i];
        }

        for(int i=0;i<m;i++)
        {
            cin>>p[i];
        }
        sort(l,l+n);
        sort(r,r+n);

        for(int i=0;i<m;i++)
        {   int time =0;
            auto pos = upper_bound(r,r+n,p[i]) - r;
            if (p[i]>=r[n-1])
                time = -1;
                
            else if (p[i]>=l[pos])
                time = 0;
            else
                time = l[pos] - p[i];
            cout<<time<<"\n";
        }

    }
    return 0;
}