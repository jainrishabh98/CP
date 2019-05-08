#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int pos=0;
    int turns = (n-11)/2;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='8')
        {
            turns--;
            if(turns==-1)
            {
                pos = i;
            }
        }
    }
    if(turns >= 0 || pos > (n-11))
        cout<<"NO";
    else
        cout<<"YES";
}