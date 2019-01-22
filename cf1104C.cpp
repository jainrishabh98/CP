#include<bits/stdc++.h>
using namespace std;
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    int n = s.length();
    int cnt1=0,cnt2=-1;
    for(int i=0;i<n;i++)
    {  
        if(s[i]=='1')
        {
            cnt1++;
            if(cnt1==5) cnt1=1;
            cout<<cnt1<<" 3\n";
        }
        else if(s[i]=='0')
        {
            cnt2 +=2;
            if(cnt2==5) cnt2=1;
            cout<<cnt2<<" 1\n";
        }
    }
}