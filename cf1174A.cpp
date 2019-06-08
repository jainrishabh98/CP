#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int a[2*n+1];
    long long int sum=0,s=0;
    for(int i=1;i<=2*n;i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    sort(a+1,a+2*n+1);
    for(int i=1;i<=n;i++)
    {
        s+=a[i];
    }
    sum -= s;
    if(s==sum)
    {
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=2*n;i++)
    {
        cout<<a[i]<<" ";
    }

}