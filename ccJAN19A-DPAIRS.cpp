#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    int mn = INT_MAX;
    int ind1,ind2;
    int mx = INT_MIN;
    for(int i=0;i<n;i++)
        {cin>>a[i];
         if(a[i]<mn)
         {
             mn = a[i];ind1 = i;
         }
        }
    for(int i=0;i<m;i++)
       { cin>>b[i];
        if(b[i]>mx)
        {
            mx = b[i]; ind2 = i;
        }
       }
    for(int i=0;i<m;i++)
        cout<<ind1<<" "<<i<<"\n";
    for(int i=0;i<n;i++)
    {
        if(i==ind1) continue;
        cout<<i<<" "<<ind2<<"\n";
    }
    
    
    return 0;
}