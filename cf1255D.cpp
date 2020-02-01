#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int r,c,k;
        cin>>r>>c>>k;
        int a[r][c];
        char ans[r][c];
        char x;
        int s = 0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
               cin>>x;
               if(x=='R')
                    {a[i][j] = 1;s++;}
                else
                    a[i][j] = 0;
            }
        }
        int cnt=0,req;
        vector<char>v;
        for(int i=0;i<26;i++)
        {
            v.push_back((char)('a'+i));
            v.push_back((char)('A'+i));
        }
        for(int i=0;i<=9;i++)
        {
            v.push_back((char)('0'+i));
        }
        int st = 0;
        req = s/k;
        int rem = s%k;
        if(rem !=0) req++;
        for(int i=0;i<r;i++)
        {
            if(i%2==0)
            {
                for(int j=0;j<c;j++)
                {
                    ans[i][j] = v[st];
                    cnt += a[i][j];
                    if(cnt == req && st < k-1)
                    {
                        st++;
                        cnt = 0;
                        if(st == rem)
                            req--;
                    }
                }
            }
            else
            {
                for(int j=c-1;j>=0;j--)
                {
                    ans[i][j] = v[st];
                    cnt += a[i][j];
                    if(cnt == req && st < k-1)
                    {
                        st++;
                        cnt = 0;
                        if(st == rem)
                            req--;
                    }
                }
            }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout<<ans[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}