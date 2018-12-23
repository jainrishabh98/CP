#include<bits/stdc++.h>
using namespace std;
int main ()
{   
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        double sum = 0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum += a[i];
        }
        sum /= n;
        if (sum == floor(sum))
            cout<<n<<"\n";
        else 
            cout<<n-1<<"\n";

    }
    return 0;
}