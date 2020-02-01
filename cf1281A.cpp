#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        if(s.substr(s.length()-2,2)=="po")
        {
            cout<<"FILIPINO\n";
        }
        else if(s.length() >=5 && s.substr(s.length()-5,5)=="mnida")
        {
            cout<<"KOREAN\n";
        }
        else
        {
            cout<<"JAPANESE\n";
        }
    }
}