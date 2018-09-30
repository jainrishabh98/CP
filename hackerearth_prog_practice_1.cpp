#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long int a,b,cnt=0;
    cin>>a>>b;
    if(a>b)
    {
        cnt = b;
        b = a;
        a = cnt;
    }
    cnt = 0;
    for(long long int i=1; (i*i)<=a;i++)
    {
        if(a%i==0)
        {
            if(b%i==0)
                cnt++;
            if(b%(a/i)==0 && (a/i)!=i)
                cnt++;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}