#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main ()
{
    double n,m,a;
    cin>>n>>m>>a;
    cout<<((ull)(ceil(n/a)) * (ull)(ceil(m/a)))<<"\n";
}