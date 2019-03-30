#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll n;
    cin>>n;
    ll prod = 1;
    vector <int> d;
    ll a = n;
    while(a!=0)
    {
        d.push_back(a%10);
        prod *= a%10;
        a /= 10;
    }
    reverse(d.begin(),d.end());
    for(int i=0;i<d.size();i++)
    {
        if(d[i]==0)
        {
            continue;
        }
        ll temp = 1;
        for(int j=0;j<d.size();j++)
        {
            if(j==i)
            {   
                if(j==0 && d[j]==1)
                    continue;
                temp *= d[j]-1;
            }
            else if (j<i)
            {
                temp *= d[j];
            }
            else
            {
                temp *= 9;
            }
        }
        // cout<<d[i]<<" "<<temp<<"\n";
        prod = max(prod,temp);
    }
    cout<<prod;
}