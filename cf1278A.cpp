#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string p,h;
        cin>>p>>h;
        sort(p.begin(),p.end());
        int n = p.length();
        int l = h.length();
        int fl=0;
        for(int i=0;i<=l - n;i++)
        {
            string t = h.substr(i,n);
            sort(t.begin(),t.end());
            if(t == p)
            {
                fl=1;
                break;
            }
        }
        if(fl==0)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
        }
        
    }
}