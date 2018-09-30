#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main()
{
    ull n,m,k;
    cin>>n>>m>>k;
    
    if(__gcd(2*n*m,k)!=k)
        cout<<"NO\n";
    else
    {
        int flag=0,a,b;
        ull quo = (2*n*m)/k;
        if(quo%n == 0)
            {
                a=n;
                b=quo/n;
            }
        else if(quo%m == 0)
            {
                a=quo/m;
                b=m;
            }
        else
        {
            vector <int> primef;
            for (int i=1;i*i<=quo;i++)
            {
                if(quo%i==0)
                    {
                    primef.push_back(i);
                    primef.push_back(quo/i);
                    }
            }
            sort(primef.begin(),primef.end());
            auto pos = lower_bound(primef.begin(),primef.end(),n) - primef.begin() ;
            pos--;
            a = primef[pos];
            if((quo/a)<m)
                b=quo/a;
            else
                flag=1;

        }
        if(flag==0)
            {
                cout<<"YES\n";
                cout<<"0 0\n";
                cout<<a<<" 0\n";
                cout<<"0 "<<b<<"\n";
            }
        else
            cout<<"NO\n";


    }
    return 0;
}
