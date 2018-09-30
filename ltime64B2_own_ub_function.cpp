#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n;
        cin>>m;
        int l[n]; int r[n];int p[m];
        for (int i=0;i<n;i++)
        {
            cin>>l[i];
            cin>>r[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>p[i];
        }
        sort(l,l+n);
        sort(r,r+n);
        for(int i=0;i<m;i++)
        {   int time =0;
            int a =0,b=n-1;
            while(a<b)
            {
                int mid = (b+a)/2;
                if(p[i]<r[mid])
                {
                    b= mid;
                }
                else if(p[i]>=r[mid])
                {
                    a = mid+1;
                }

            }
            if(p[i]>=r[n-1])
                time =-1;
            else if(p[i]<r[a] && p[i]>=l[a])
                time =0;
            else
                time = l[a] - p[i];

            cout<<time<<"\n";


        }

    }
    return 0;
}
