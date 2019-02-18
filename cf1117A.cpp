#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int a[n];
    int mx= 0;
    for(int i=0;i<n;i++)    {cin>>a[i];mx = max(a[i],mx);}
    int len = 0;
    for(int i=0;i<n;i++)
    {
        int l = 0;
        while(a[i]==mx && i<n)
        {
            i++;
            l++;
        }
        len = max(len,l);
    }
    cout<<len;
}