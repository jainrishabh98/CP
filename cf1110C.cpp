#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>q;
    int a[q],b=1;
    for(int i=0;i<q;i++)    cin>>a[i];
    for(int i=0;i<q;i++)    
    {
        int t = a[i],cnt=0;
        if(t&(t-1))
        while(t!=0)
        {
            t /= 2;
            cnt++;
        }


    }
}