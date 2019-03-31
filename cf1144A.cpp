#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        sort(s.begin(),s.end());
        int flag=0;
        for(int j=1;j<s.length();j++)
        {
            if(s[j] - s[j-1] !=1)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
}