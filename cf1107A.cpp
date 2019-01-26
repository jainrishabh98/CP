#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int q;
    cin>>q;
    int n;
    string s;
    while(q--)
    {
    cin>>n;
    cin>>s;
    if(n>=3)
    {
        cout<<"YES\n2\n"<<s[0]<<" ";
        for(int i=1;i<n;i++)
            cout<<s[i];
        cout<<"\n";
    }
    else
    {
        if(s[1]<=s[0])
            cout<<"NO\n";
        else
            cout<<"YES\n2\n"<<s[0]<<" "<<s[1]<<"\n";
    }
    }

}