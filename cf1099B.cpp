#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int t =2;
    int kh=1,ky=1,i=0;
    while((kh*ky)<n)
    {
        if(i==0)
        {
            i=1;
            kh++;
        }
        else
        {
            i=0;ky++;
        }
        t++;
    }
    cout<<t<<"\n";
    return 0;
}