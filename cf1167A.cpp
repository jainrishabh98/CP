#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        int fl=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='8' && n-i >=11)
            {
                fl=1;
                break;
            }
        }
        if(fl==0)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
        }
    }

}