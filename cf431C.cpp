#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m = 1e9 + 7;
ll part[101];// stores the number of ways to represent i as sum of numbers from d to k
ll par[101]; // stores the number of ways to represent i as sum of numbers from 1 to k
/*
For the case: 10 6 3
partition of 10 -> fixed_number + partition of (10 - fixed_number)
2 cases arise: 1. if fixed_number < d, then part(10-fixed_number) has to be used
               2. if fixed_number >=d, then par(10 - fixed_number) has to be used as a number >=d has already been included
Both par and part are easily calculated through dynamic programming
*/
int main ()
{   
    int n,k,d;
    cin>>n>>k>>d;
    for(int i=1;i<=n;i++)
    {
        if(i==1)
            par[i]=1;
        else
        {   if(i>k) par[i]=0;
            else par[i] = 1;
            for(int j=1;j<=min(i-1,k);j++)
            {
                par[i] = (par[i] + par[i-j])%m;
            }
        }
    }
    for(int i=1;i<=n;i++)
        {
            if(i<d)
                part[i] = 0;
            else
            {
                if(i>k) part[i]=0;
                else part[i] = 1;
                for(int j=1;j<=min(i-1,k);j++)
                {
                    if(j<d)
                        part[i] = (part[i] +  part[i-j])%m;
                    else
                        part[i] = (part[i] + par[i-j])%m;
                }
            }
            // cout<<part[i]<<" ";
        }
        cout<<part[n]<<"\n";
    return 0;
}