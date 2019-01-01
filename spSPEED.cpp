#include<bits/stdc++.h>
using namespace std;
int main ()
{   int t;
    cin>>t;
    while(t--)
    {   int s1,s2;
        cin>>s1>>s2;
        if(s1==0 || s2==0)
            { cout<<"1\n";continue;}
        int g = __gcd(abs(s1),abs(s2));
        s2 = s2 - s1;
        int hit = abs(s2)/g;
        cout<<hit<<"\n";
    }
    return 0;
}