#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin>>n;
    string s[n];
    cin.get();
    for(int i=0;i<n;i++)
    {
        getline(cin,s[i]);
    }
    stack <pair<int,int>> st[26];
    vector<char> v[20000];
    // vector <char> q;
    // v.push_back(q);
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<s[i].length();j++)
        {
            char x = s[i][j];
            if(x=='{')
            {
                // cout<<i<<" "<<j<<" "<<"here1"<<"\n";
                cnt++;
                // v.push_back(q);
            }
            else if(x=='}')
            {
                // cout<<i<<" "<<j<<" "<<"here2"<<"\n";
                while(!v[cnt].empty())
                {
                    char p = v[cnt].back();
                    v[cnt].pop_back();
                    st[p-'a'].pop();
                }
                cnt--;
                // v.pop_back();
            }
            else if(x>='a' && x<='z')
            {
                // cout<<i<<" "<<j<<" "<<"here3"<<"\n";
                v[cnt].push_back(x);
                if(!st[x-'a'].empty())
                {
                    cout<<i+1<<":"<<j+1<<": warning: shadowed declaration of "<<x<<", the shadowed position is "<<st[x-'a'].top().first<<":"<<st[x-'a'].top().second<<"\n";
                }
                st[x-'a'].push({i+1,j+1});
            }
        }
    }
}