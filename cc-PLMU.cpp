#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n;
        long long int arr[3] = {0};
        for(int i=0;i<n;i++)
        {
            cin>>p;
            if(p==0 || p==2)
                arr[p]++;
        }
        long long int sum = (arr[0]*(arr[0]-1))/2 + (arr[2]*(arr[2]-1))/2 ;
        cout<<sum<<"\n";
    }
}