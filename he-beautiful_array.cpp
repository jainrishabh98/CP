#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int a[n];
    vector <int> v;
    int x;
    int mx=0;
    for(int i=0;i<n;i++)    {cin>>a[i];mx=max(mx,a[i]);}
    for(int i=0;i<n;i++)    
    {cin>>x;
     if(a[i]!=mx)
        v.push_back(x);
    }
    
}