#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    double p[n];
    double sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        sum += p[i];
    }
    sum /= n;
    cout<<fixed;
    cout<<setprecision(5)<<sum;
}