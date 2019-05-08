#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long int n,k;
    cin>>n>>k;
    if(k==1)
    {
        cout<<"YES\n"<<n;
        return 0;
    }
    if(n<((k*(k+1))/2))
    {
        cout<<"NO";
        return 0;
    }
    n -= (k*(k+1))/2;
    long long int a[k];
    long long int t = n/k;
    n = n%k;
    for(int i=0;i<k;i++)
    {
        a[i] = i+1+t;
    }
    if(t == 0 && n!=0 && k<=3)
    {
        if(k==2 || n==2)
        {
            cout<<"NO";
            return 0;
        }
        else
        {
            cout<<"YES\n1 2 4";
            return 0;
        }

    }
    else
    {
        if(t !=0 || n==0)
            a[k-1] += n;
        else
        {
            a[k-2]++;
            a[k-1] += n-1;
        }
    }
    cout<<"YES\n";
    for(int i=0;i<k;i++)
    {
        cout<<a[i]<<" ";
    }
}