#include<bits/stdc++.h>
using namespace std;
int main()
{
int t,n,m,k,l;
cin>>t;
        while (t--) {
           cin>>n>>m>>k>>l;
            int ar[n];
            for(int i=0;i<n;i++)
                cin>>ar[i];
            sort(ar,ar+n);
            int people[n];
            for(int i=0;i<n;i++)
            {
                people[i]=max(0,(m+i-(ar[i]/l)));
            }
            int time[n+1];int mn=1e9,temp;
            for (int i = 0; i < n; i++) {
                int x=(int)ceil((double)(ar[i])/(double) (l))*l;
                if(x==ar[i])
                    temp=x+l;
                else temp=x;
                time[i]=((people[i])*l)+temp -ar[i];
                
                if(time[i]<mn && ar[i]<k)
                    mn=time[i];
                
            }
            time[n]=(n+1+m)*l-k;
            cout<<(min(mn,time[n]))<<"\n";
        }
return 0;
}