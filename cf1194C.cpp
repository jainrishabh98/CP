#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int q;
    cin>>q;
    while(q--)
    {
        string s,t,p;
        cin>>s>>t>>p;
        int a[26]={0};
        for(int i=0;i<p.length();i++)
        {
            a[p[i]-'a']++;
        }
        int j=0,flag=0;
        for(int i=0;i<t.length();i++)
        {
            if(t[i]==s[j] && j<s.length())
            {
                j++;
            }
            else if(a[t[i]-'a']>0)
            {
                a[t[i]-'a']--;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==0 && j==s.length())
            cout<<"YES\n";
        else
        {
            cout<<"NO\n";
        }
        
    }
}