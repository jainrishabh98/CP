#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        if(n%2!=0)
            cout<<"NO\n";
        else{int flag=0;
            int l = n/2;
            for(int i=0;i<l;i++)
            {
                if(a[i]==-1 || a[l+i]==-1)
                {
                    if(a[i]==-1 && a[l+i]!=-1)
                        a[i]=a[l+i];
                    else if(a[i]!=-1 && a[l+i]==-1)
                        a[l+i]=a[i];
                    else
                        {a[l+i]=1;
                        a[i]=1;}
                }
                else{
                    if(a[i]!=a[l+i])
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1)
                cout<<"NO\n";
            else
            {
                cout<<"YES\n";
                for (int i=0;i<n;i++)
                {
                    cout<<a[i]<<" ";
                }
            }
        }
    }
    return 0;
}
