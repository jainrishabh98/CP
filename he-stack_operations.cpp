#include<bits/stdc++.h>
using namespace std;
long long int a[2000005];
long long int *it1,it2;
int main ()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    a[n] = 0;
    a[n+1] = 0;
    if(k%n==0 && (k/n)%2!=0) {cout<<"-1";return 0;}
    if(k>n+1) k = n+1;
    it1 = max_element(a,a+k-1);
    it2 = a[k];
    cout<<max(*it1,it2);
}