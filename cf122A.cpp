#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    vector <int> factors;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            factors.push_back(i);
            factors.push_back(n/i);
        }
    }
    for(auto i:factors)
    {
        int flag=0;
        while(i!=0)
        {
            int dig = i%10;
            if(dig!=4 && dig!=7)    {flag=1;break;}
            i /= 10;
        }
        if(flag==0) {cout<<"YES";return 0;}
    }
    cout<<"NO";
    return 0;
}