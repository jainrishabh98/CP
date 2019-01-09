#include<bits/stdc++.h>
using namespace std;
int tree[100005];
int n;
int sum(int k)
{
    int s = 0;
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
    memset(tree,0,sizeof(tree));
    cin>>n;
    int z[n];
    for(int i=0;i<n;i++)
    {
        cin>>z[i];
        if(z[i]%2==0)
        {
            update(i+1,1);
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0)
        {
            if(z[b-1]%2!=0 && c%2==0)
                update(b,1);
            else if(z[b-1]%2==0 && c%2!=0)
                update(b,-1);
            z[b-1] = c;
        }
        else if(a==1)
        {
            cout<<sum(c) - sum(b-1)<<"\n";
        }
        else
            cout<<(c-b+1)-(sum(c) - sum(b-1))<<"\n";
    }
    return 0;
}