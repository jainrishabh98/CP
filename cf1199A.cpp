#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,x,y;
    cin>>n>>x>>y;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        int j = i-1;
        int k = i+1;
        int cntx = x,cnty = y;
        while(j>=0 && cntx>0)
        {
            if(a[i] < a[j])
            {
                cntx--;
                j--;
            }
            else 
                break;
        }
        while(k<n && cnty>0)
        {
            if(a[i] < a[k])
            {
                cnty--;
                k++;
            }
            else 
                break;
        }
        if((cntx==0 || j==-1) && (cnty==0 || k==n))
        {
            cout<<i+1;
            return 0;
        }
    }
}