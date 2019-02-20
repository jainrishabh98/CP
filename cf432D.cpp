#include<bits/stdc++.h>
using namespace std;
int main ()
{
    string s;
    cin>>s;
    int l = s.length();
    int lps[l]; 
    lps[0] = 0;
    int len = 0; 
    int i = 1; 
    while (i < l) 
    { 
        if (s[i] == s[len]) 
        { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else 
        { 
         
            if (len != 0) 
            { 
                len = lps[len-1]; 
            } 
            else 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
    int g = lps[l-1];
    int cnt[g+3]={0};
    while(g!=0)
    {
        // cout<<g<<" ";
    for(int i=l-1;i>=0;i--)
    {   cout<<lps[i]<<" ";
        if(lps[i]>=g)
        {
            cnt[g]++;
        }
    }
    cout<<"\n";
    g = lps[g-1];
    }
    int num = 0;
    for(int i=1;i<=g+2;i++)
    {
        if(cnt[i]!=0)
            num++;
    }
    cout<<num+1<<"\n";
    for(int i=1;i<=g+2;i++)
    {
        if(cnt[i]!=0)
        {
            cout<<i<<" "<<cnt[i]<<"\n";
        }
    }
    cout<<l<<" "<<1;
}