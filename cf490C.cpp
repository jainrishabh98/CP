#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    string s;
    cin >> s;
    ll a, b;
    cin >> a >> b;
    int l = s.length();
    vector <int> v1,v2;
    ll temp=0;
    for(int i=0;i<l-1;i++)
    {
        temp = (temp*10 + s[i]-'0') % a;
        if(temp==0)
            v1.push_back(i);
    }
    temp = 1;
    ll tmp = 0;
    for(int i=l-1;i>=1;i--)
    {
        tmp = (tmp + (s[i]-'0')*temp)%b;
        temp = (temp*10)%b;
        if(tmp==0)
        {
            v2.push_back(i);
        }
    }
    sort(v2.begin(),v2.end());
    for(auto i:v1)
    {
        if(binary_search(v2.begin(),v2.end(),i+1) && s[i+1]!='0')
        {
            cout<<"YES\n";
            for(int j=0;j<=i;j++)
            cout<<s[j];
            cout<<"\n";
            for(int j=i+1;j<l;j++)
            cout<<s[j];
            return 0;
        }
    }
    cout<<"NO";
}