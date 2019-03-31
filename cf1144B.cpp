#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int n;
    cin>>n;
    int a[n];
    int odd = 0,even = 0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]%2==0) even++;
        else odd++;
    }
    sort(a,a+n);
    long long int sum = 0;
    if(abs(odd-even) <= 1)
    {
        cout<<0;
        return 0;
    }
    if(odd>even)
    {   odd -= even;
        odd--;
        for(int i=0;i<n;i++)
        {
            if(odd==0)
                break;
            if(a[i]%2!=0)
            {
                odd--;
                sum += a[i];
            }
            
        }
    }
    else
    {   even -= odd;
        even--;
        for(int i=0;i<n;i++)
        {
            if(even==0)
                break;
            if(a[i]%2==0)
            {
                even--;
                sum += a[i];
            }
            
        }
    }
    cout<<sum;
}