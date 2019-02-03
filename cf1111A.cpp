#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s,t;
    cin>>s>>t;
    int l1 = s.length();
    if(t.length()!=l1)
        cout<<"No";
    else
    {
        for(int i=0;i<l1;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='u' || s[i]=='i')
            {
                if(!(t[i]=='a' || t[i]=='e' || t[i]=='o' || t[i]=='u' || t[i]=='i'))
                {
                    cout<<"No";return 0;
                }
            }
            else
            {
                if((t[i]=='a' || t[i]=='e' || t[i]=='o' || t[i]=='u' || t[i]=='i'))
                {
                    cout<<"No";return 0;
                }
            }
        }
        cout<<"Yes";
    }
}