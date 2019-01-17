#include<bits/stdc++.h>
using namespace std;
struct st{
    int num,ind,clr;
};
bool comp(st a, st b)
{
    return (a.num < b.num);
}
bool comp2(st a, st b)
{
    return (a.ind < b.ind);
}
int main ()
{
    int n,k;
    cin>>n>>k;
    st a[n];
    int cnt[5001]={0};
    for(int i=0;i<n;i++)
        {cin>>a[i].num;cnt[a[i].num]++;a[i].ind=i;}
    int flag=0;
    for(int i=0;i<n;i++)   if(cnt[a[i].num]>k) flag=1;
    if(n<k || flag==1)
        {cout<<"NO\n";return 0;}
    sort(a,a+n,comp);
    cout<<"YES\n";
    int temp=1;
    for(int i=0;i<n;i++)
    {   
        if(temp == k+1) temp = 1 ;
        a[i].clr = temp;
        temp++;
    }
    sort(a,a+n,comp2);
    for(int i=0;i<n;i++)
    {
        cout<<a[i].clr<<" ";
    }
}