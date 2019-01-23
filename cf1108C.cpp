#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s,a[6];
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(i%3==0)
        {
            a[0].push_back('R');
            a[1].push_back('G');
            a[2].push_back('B');
            a[3].push_back('R');
            a[4].push_back('G');
            a[5].push_back('B');
        }
        else if(i%3==1)
        {
            a[0].push_back('G');
            a[1].push_back('B');
            a[2].push_back('G');
            a[3].push_back('B');
            a[4].push_back('R');
            a[5].push_back('R');
        }
        else
        {
            a[0].push_back('B');
            a[1].push_back('R');
            a[2].push_back('R');
            a[3].push_back('G');
            a[4].push_back('B');
            a[5].push_back('G');
        }
    }
    int cnt[6]={0};
    for(int i=0;i<n;i++)
    {
        if(s[i]!=a[0][i])  cnt[0]++;
        if(s[i]!=a[1][i])  cnt[1]++;
        if(s[i]!=a[2][i])  cnt[2]++;
        if(s[i]!=a[3][i])  cnt[3]++;
        if(s[i]!=a[4][i])  cnt[4]++;
        if(s[i]!=a[5][i])  cnt[5]++;
    }
    int mn = *(min_element(cnt,cnt+6));
    for(int i=0;i<6;i++)
    {
        if(cnt[i]==mn)
        {
            cout<<cnt[i]<<"\n";
            cout<<a[i];
            break;
        }
    }
}