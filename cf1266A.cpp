#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    string ans[n];
    for(int i=0;i<n;i++)
    {
        cin>>s;
        int fl=0,sum=0,fl1=0;
        for(int j=0;j<s.length();j++)
        {
            if(s[j]=='0')
                fl++;
            if((s[j]-'0')%2==0 && s[j]!='0')
                fl1=1;
            sum += s[j]-'0';
        }
        if(sum%3==0 && fl>=1 && (fl1==1 || fl>1))
            ans[i] = "red";
        else
            ans[i] = "cyan";
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<"\n";
    }
}