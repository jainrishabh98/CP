#include<bits/stdc++.h>
using namespace std;
int main ()
{
    string s1,s2;
    cin>>s1>>s2;
    int flag,len1=s1.length(),len2=s2.length();
    set <int> v1;
    for(int i=1;i<=min(len1,len2);i++)
    {
        if(len1%i == 0 && len2%i==0)
        {
            v1.insert(i);
        }
    }
    int cnt=0;
    for(auto l:v1)
    {   flag=0;
        // cout<<l<<" ";
        string str = s1.substr(0,l);
        for(int k=0;k<s1.length();k+=l)
        {
            if(str!=s1.substr(k,l))
            {
                flag=1;break;
            }
        }
        for(int k=0;k<s2.length();k+=l)
        {
            if(str!=s2.substr(k,l))
            {
                flag=1;break;
            }
        }
        if(flag==0)
            cnt++;
    }
    // cout<<s1<<" "<<s2<<"\n";
    cout<<cnt<<"\n";
    return 0;
}