#include<bits/stdc++.h>
using namespace std;
int bit[27][200001];
string s;
int m;
int vis[200001];
void update(char c,int k, int x)
{
    while(k<=s.size())
    {
        bit[c][k] += x;
        k += (k&(-k));
    }
}
int query(char c,int k)
{   int sum=0;
    while(k>=1)
    {
        sum += bit[c][k];
        k -= (k&(-k));
    }
    return sum;
}
int ans;
int del(int k,char c)
{
    int mid,low=1,high=s.size();
    while(low<=high)
    {   
        mid = (low+high)/2;
        if(query(c,mid)>=k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    update(c,ans,-1);
    return ans;
}
int main ()
{
    cin>>s;
    cin>>m;
    char c;int k;
    for(int i=0;i<s.size();i++)
    {
        update(s[i] -'a',i+1,1);
    }
    while(m--)
    {
        cin>>k>>c;
        c -= 'a';
        int pos = del(k,c);
        vis[pos-1]=1;
    }
    for(int i=0;i<s.size();i++)
    {
        if(vis[i]==0)
            cout<<s[i];
    }
}