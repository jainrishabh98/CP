#include<bits/stdc++.h>
using namespace std;
struct st{
    string s;
    int len;
    int in;
};
struct stt{
    char c;
    int ind;
};
bool comp (st a, st b)
{
    return ((a.len != b.len) ? (a.len < b.len) : (a.s < b.s));
}
bool comp2 (stt a, stt b)
{
    return (a.ind < b.ind);
}
int main ()
{   int n;
    cin>>n;
    int temp = 2*n -2;
    st v[temp];
    stt ans[temp];
    string s1;
    string s2;
    for (int i=0;i<temp;i++)
    {
        cin>>v[i].s;v[i].len = v[i].s.length();v[i].in = i+1;
    }
    sort(v,v+temp,comp);
    char start = v[0].s[0];
    ans[0].c = 'P';ans[0].ind = v[0].in;
    ans[1].c = 'S';ans[1].ind = v[1].in;
    char end = v[1].s[0];
    int cnt = 0;
    for (int i=0;i<temp;i++)
    {
        if(v[i].s[0] == start)
            cnt++;

    }
    if(cnt < (n-1))
        {start = v[1].s[0];ans[0].c = 'S';ans[1].c = 'P'; end = v[0].s[0];}
    s1.push_back(start);
    s2.push_back(start); // anyone of s1 or s2 is the correct string
    s1.append(v[temp-1].s);
    s2.append(v[temp-2].s);
    string tmp =s1;
    for(int k=0;k<=1;k++)
    {   cnt=1;int cnt1=0,cnt2=0;
        if(k==1) tmp = s2;
        for(int i=2;i<temp;i++)
        {
            if(i%2==0) cnt++;
            string tm = tmp.substr(0,cnt);
            string tp = tmp.substr(n-cnt,cnt);
            // cout<<v[i].s<<" "<<tm<<" "<<tp<<"\n";
            if(v[i].s == tm && v[i].s != v[i-1].s)
                {ans[i].c = 'P';cnt1++;}
            else if(v[i].s == tp)
                {ans[i].c = 'S';cnt2++;}
        
            ans[i].ind = v[i].in;
        }
        if(cnt1==n-2 && cnt2==n-2) // if s1 is correct then break
            break;
    }
    sort(ans,ans+temp,comp2);
    for (int i=0;i<temp;i++)
    { cout<<ans[i].c;}
    cout<<"\n";
    return 0;
}