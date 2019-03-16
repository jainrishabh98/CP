#include<bits/stdc++.h>
using namespace std;
int main ()
{
    string s;
    cin>>s;
    int l = s.length();
    int fl1=0,fl2=0,flag=0;
    int lwt = 0;
    vector <int> cntb;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='M')
            {fl1++;flag++;}
        else
        {   if(flag!=0)
                lwt = max(0,lwt - fl1 + 1);
            cntb.push_back(flag);
            fl2++;
            fl1=0;
        }
    }
    if(flag==0 || fl2==0) cout<<0;
    else  cout<<cntb[fl2-1]+lwt;
}