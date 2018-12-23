#include<bits/stdc++.h>
using namespace std;
int main ()
{   
    long long int n;
    cin>>n;
    if (n<=1)
        cout<<"TAK\n";
    else if ((n&(n-1)) == 0)  // bitwise have lowest precedence
        cout<<"TAK\n";
    else
        cout<<"NIE\n";
    return 0;
}