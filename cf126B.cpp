#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int l = s.length();
    if(l==1 || l==2)
        {cout<<"Just a legend\n";return 0;}
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

    if(lps[l-1]==0)
        cout<<"Just a legend\n";
    else
    {
        for(int i=l-2;i>=1;i--)
        {   
            if(lps[i]==lps[l-1])
            {
                cout<<s.substr(0,lps[i])<<"\n";return 0;
            }
                
        }
        if(lps[lps[l-1]-1]==0)
            cout<<"Just a legend\n";
        else
            cout<<s.substr(0,lps[lps[l-1]-1])<<"\n";
    }
    
    
    return 0;
}