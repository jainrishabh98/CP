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
        string s,c;
        cin>>s>>c;
        int n = s.length();
        string ans = "---";
        int a[26];
        for(int i=0;i<26;i++)
            a[i] = -1;
        int fl=0;
        for(int i=0;i<n;i++)
        {
            int x = s[i] - 'A';
            a[x] = max(a[x],i);
        }
        for(int i=0;i<n;i++)
        {
            int x = s[i] - 'A';
            for(int j=0;j<x;j++)
            {
                if(a[j]>i)
                {
                    swap(s[i],s[a[j]]);
                    fl=1;
                    break;
                }
            }
            if(fl==1)
                break;
        }
        if(s<c)
            ans = s;
        cout<<ans<<"\n";
    }
}