#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b,b+n);
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(b[i]!=a[i])
        {
            cnt++;
        }
        if(cnt>2)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

}