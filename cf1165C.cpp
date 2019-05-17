#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string ans;
    ans.push_back(s[0]);
    int cnt=0;
    for(int i=1;i<n;i++)
    {
        if(cnt%2==0 && ans[cnt]==s[i])
        {
            continue;
        }
        else
        {
            ans.push_back(s[i]);
            cnt++;
        }
    }
    cnt++;
    if(cnt%2!=0)
    {
        ans.pop_back();
        cnt--;
    }
    cout<<n-cnt<<"\n"<<ans;
}