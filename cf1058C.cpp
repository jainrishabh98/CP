#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char x;
    int a[n];
    int mx=0;
    int s=0;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a[i] = x - int('0');
        mx = max(mx,a[i]);
        s += a[i];
    }
    int v=0;
    if(mx==0)
        {
            cout<<"YES\n";
            return 0;
        }
    for(int j=mx;j<s;j++)
    {   int flag=0;
        for(int i=0;i<n;i++)
        {   int sum = 0;
            while(sum<j && i<n)
            {
                sum += a[i];
                i++;
            }
            while(a[i]==0 && i<n)
                i++;
            if(sum!=j)
                {flag=1;break;}
            i--;
        }   
        if(flag==0)
            {v=1;break;}
    }
    if(v==1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}