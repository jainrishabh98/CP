#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cn1=0,cn2=0,cn3=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0') cn1++;
        else if(s[i]=='1') cn2++;
        else cn3++;
    }
    
    int cnt[3];cnt[0] = n/3 - cn1;cnt[1] =n/3 - cn2;cnt[2]=n/3 - cn3; 
    // cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<" ";
    if(cnt[2]>0)
    {
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!='2')
            {
                if(cnt[s[i]-'0']<0)
                {   cnt[s[i]-'0']++;
                    s[i]='2';
                    
                    cnt[2]--;
                    if(cnt[2]==0) break;
                }
            }
        }
    }
    else if(cnt[2]<0)
    {   int i=0;
        while(s[i]!='2') i++;
        for(;i<n;i++)
        {
            if(s[i]=='2')
            {
                if(cnt[0]>0)
                {   
                    cnt[0]--;
                    s[i]='0';
                    cnt[2]++;
                    if(cnt[2]==0) break;
                }
                else
                {
                    cnt[1]--;
                    s[i]='1';
                    cnt[2]++;
                    if(cnt[2]==0) break;
                }
                
            }
        }

    }
    if(cnt[1]>0)
    {
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!='1')
            {
                if(cnt[s[i]-'0']<0)
                {   
                    cnt[s[i]-'0']++;
                    s[i]='1';
                    cnt[1]--;
                    if(cnt[1]==0) break;
                }
            }
        }
    }
    else if(cnt[1]<0)
    {   int i=0;
        while(s[i]!='1') i++;
        for(;i<n;i++)
        {
            if(s[i]=='1')
            {
                if(cnt[0]>0)
                {   
                    cnt[0]--;
                    s[i]='0';
                    cnt[1]++;
                    if(cnt[1]==0) break;
                }
            }
        }

    }
    for(int i=0;i<n;i++)
        cout<<s[i];
}