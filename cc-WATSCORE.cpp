#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p,s;
        cin>>n;
        int arr[11] = {0};
        for(int i=0;i<n;i++)
        {
            cin>>p>>s;
            p--;
            arr[p] = max(arr[p],s);
        }
        int sum = 0;
        for(int i=0;i<=7;i++)
            sum += arr[i];
        cout<<sum<<"\n";
    }
}