#include<bits/stdc++.h>
using namespace std;
int tree[1000005];
int n;
int sum(int k)
{   int s=0;
    while(k>=1)
    {   
        s += tree[k];
        k -= (k&(-k));
    }
    return s;
}
void update(int k, int x)
{
    while(k<=n)
    {
        tree[k] += x;
        k += (k&(-k));
    }
}
int main ()
{
    cin>>n;
    memset(tree,0,sizeof(tree));
    int a[n];
    int tmp[n];
    int l[n],r[n],cnt[n];
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        tmp[i] = a[i];
    }
    sort(tmp,tmp+n);
    for(int i=0;i<n;i++)
    {
        a[i] = lower_bound(tmp,tmp+n,a[i]) - tmp;

    }
    for (int i=0;i<n;i++)
    {
        cnt[a[i]]++;
        l[i] = cnt[a[i]];    // frequency array for 0 to i index
        // cout<<l[i]<<" ";
    }
 
    memset(cnt,0,sizeof(cnt));
    for (int i=n-1;i>=0;i--)
    {
        cnt[a[i]]++;
        r[i] = cnt[a[i]];    // frequency array for n-1 to i index
        update(r[i]+1,1);
        // cout<<r[i]<<" ";
    }
    long long int result = 0;
    for(int i=0;i<n;i++)
    {
        update(r[i]+1,-1);
        result += (sum(l[i]) - sum(1));

    }
    cout<<result<<"\n";
    return 0;
}