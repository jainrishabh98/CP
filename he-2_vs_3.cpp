#include<bits/stdc++.h>
using namespace std;
int n;
int tree[2][100005];
long long int sum(int k,int p)
{
    long long int s=0;
    while(k>=1)
    {
        s += tree[p][k];
        k -= (k&(-k));
    }
    return s;
}
void update(int k,int x,int p)
{
    while(k<=n)
    {
        tree[p][k] += x;
        k += (k&(-k));
    }
}
int main ()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    string s;
    cin>>n;
    cin>>s;
    cin>>q;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0') continue;
        if((n-1-i)%2==0)
        {
            update(i+1,1,1);
        }
        else
        {
            update(i+1,1,0);
        }
    }
    int t,l,r;
    while(q--)
    {
        cin>>t;
        if(t==0)
        {
            cin>>l>>r;
            long long int p1,p2;
            p1 = sum(r+1,1) - sum(l,1);
            p2 = sum(r+1,0) - sum(l,0);
            if((n-1-r)%2==0)
            {
                cout<<(p1+p2*2)%3<<"\n";
            }
            else
            {
                cout<<(p1*2+p2)%3<<"\n";
            }
        }
        else
        {
            cin>>l;
            if(s[l]=='0')
                {
                    s[l]='1';
                    if((n-1-l)%2==0)
                    {
                            update(l+1,1,1);
                    }
                    else    update(l+1,1,0);
                }
        }
    }
}