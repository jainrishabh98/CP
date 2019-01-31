#include<bits/stdc++.h>
using namespace std;
int main ()
{
    string s1,s2,s3;
    int cnt[26]={0};
    cin>>s1>>s2>>s3;
    for(int i=0;i<s1.length();i++)
    {
        cnt[s1[i]-65]++;
    }
    for(int i=0;i<s2.length();i++)
    {
        cnt[s2[i]-65]++;
    }
    for(int i=0;i<s3.length();i++)
    {
        cnt[s3[i]-65]--;
    }
    for(int i=0;i<26;i++)
    {
        if(cnt[i]!=0)
            {cout<<"NO";return 0;}
    }
    cout<<"YES";

}