#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int x;
    int cnt[3]={0};
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x==0)
            cnt[0]++;
        else if(x>0)
            cnt[1]++;
        else
            cnt[2]++;
    }
    if(cnt[1]>=ceil(n/2.0))
        cout<<1;
    else if(cnt[2]>=ceil(n/2.0))
        cout<<-1;
    else
        cout<<0;
}