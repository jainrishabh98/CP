#include<bits/stdc++.h>
using namespace std;
//try to solve using dp
int main ()
{
    string s;
    cin>>s;
    
    for(int i=0;i<s.length();i++)
    {   if((s[i]-48) %8 ==0)
            {cout<<"YES\n"<<s[i]<<"\n";return 0;}
        for(int j=i+1;j<s.length();j++)
        {   if(((s[i]-48)*10 + (s[j]-48)) %8 == 0)
                {cout<<"YES\n"<<(s[i]-48)*10 + (s[j]-48)<<"\n";return 0;}
            for(int k=j+1;k<s.length();k++)
            {
                if((4*(s[i]-48)+2*(s[j]-48)+(s[k]-48))%8==0)
                {  
                    cout<<"YES\n"<<((s[i]-48)*100)+((s[j]-48)*10)+(s[k]-48)<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<"NO\n";
    return 0;
}