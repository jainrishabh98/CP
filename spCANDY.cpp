#include<bits/stdc++.h>
using namespace std;
int main ()
{   int n;
    cin>>n;
    while(n!= -1)
    {
        int a[n];
        long long int sum = 0;
        for(int i=0;i<n;i++)
           { cin>>a[i]; sum += a[i];}
        
        if ((sum % n) != 0)
            cout<<"-1\n";
        else
        {   int moves = 0;
            sum /= n;
            for(int i=0;i<n;i++)
            { 
                if(a[i] > sum)
                {
                    moves += (a[i] - sum) ;
                }
            }
            cout<<moves<<"\n";
        }
        
        cin>>n;
    }
    return 0;
}