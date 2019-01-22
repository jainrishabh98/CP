#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   string s;
   cin>>s;
   stack<char>t;
   ll c=0;
   for(ll i=0;i<s.length();i++)
   {
       if(t.empty()){t.push(s[i]);}
       else
       {
           if(t.top()==s[i])t.pop(),c++;
           else t.push(s[i]);
       }
   }
//    cout<<c;
   if(c&1)cout<<"Yes"; 
   else cout<<"No";
}