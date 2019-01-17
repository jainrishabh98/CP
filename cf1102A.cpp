#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    if(n%4==0 || n%4==3)  cout<<"0\n";
    else if(n%4==1 || n%4==2) cout<<"1\n";
    return 0;
}