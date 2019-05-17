#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    string s[n];
    int a[26]={0};
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        a[s[i][0]-'a']++;
    }
    int ans = 0;
    for(int i=0;i<26;i++)
    {
        int c = ceil(a[i]/2.0);
        int d = a[i] - c;
        ans += (((d*(d-1))/2) + ((c*(c-1))/2));
    }
    cout<<ans;
    
}