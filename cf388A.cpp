#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    set <int> a;
    vector <int> v;
    int x;
    int cnt[101]={0};
    for(int i=0;i<n;i++)
    {   cin>>x;
        cnt[x]++;
    }
    int ans = 0;
    while(*(max_element(cnt,cnt+101))!=0)
    {
    int num=0;
    for(int i=0;i<=100;i++)
    {
        if(cnt[i]==0)
        {
            continue;
        }
        else
        {   
            v.push_back(i);
            cnt[i]--;
            num++;
        }
    }
    int mx = v[num-1];
    if(*(max_element(cnt,cnt+101))!=0 && num<=mx)
    {   int c = 0,tem=0,q;
        for(auto j:v)
        {   
            if(cnt[j]!=0 && num<=mx && j!=0)
            {   tem = 0;
                for(q=cnt[j];q>max(0,cnt[j]-j+c);q--)
                {
                    tem++;
                    num++;
                    if(num==mx+1)
                        {q--;break;}
                }
                c += tem;
                cnt[j] = q;
            }
            c++;
        }
    }
    ans++;
    v.clear();
    }
    cout<<ans;
}