#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int l,r;
    cin>>l>>r;
    map<int,int> mp;
    for(int i=l;i<=r;i++)
    {
        int p = i;
        mp.clear();
        int fl = 0;
        while(p!=0)
        {
            int a = p%10;
            if(mp.find(a)==mp.end())
            {
                mp[a]=1;
            }
            else
            {
                fl = 1;
                break;
            }
            
            p /= 10;
        }
        if(fl==0)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
}