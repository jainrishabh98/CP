#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull; 
int main ()
{   
    ull t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n = n-1;
        ull b=0, N=0, B=0;
        ull c = (n/26);
        ull k = pow(2.0,c);
        n = n%26 ;
        if(n<2)
            b = 1;     
        else if (n<10)
            N = 1;
        else
            B = 1;
        
        cout<<k*b<<" "<<k*N<<" "<<k*B<<"\n";
        
    }
    return 0;
}