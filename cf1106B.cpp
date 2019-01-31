#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct st1{
    ll a,c,ind;
};
struct st2{
    ll t,d;
};
bool comp(st1 x, st1 y)
{
    return (x.c==y.c) ? (x.ind < y.ind) : (x.c < y.c);
}
int main ()
{
    ll n,m;
    cin>>n>>m;
    st1 s[n],h[n];
    st2 p[m];
    for(int i=0;i<n;i++)
        {cin>>s[i].a;s[i].ind=i;h[i].a=s[i].a;h[i].ind=i;}
    for(int i=0;i<n;i++)
        {cin>>s[i].c;h[i].c=s[i].c;}
    for(int i=0;i<m;i++)
        {cin>>p[i].t>>p[i].d;p[i].t--;}
    sort(h,h+n,comp);
    stack <st1> st;
    for(int i=n-1;i>=0;i--)
    {
        st.push(h[i]);
    }
    ll cost=0;
    int flag=0;
    for(int i=0;i<m;i++)
    {   
        cost = 0;
        if(flag==1)
            {cout<<"0\n";continue;}
        if(s[p[i].t].a >= p[i].d)
        {
            s[p[i].t].a -= p[i].d;
            cost = p[i].d*s[p[i].t].c;
            cout<<cost<<"\n";
        }
        else
        {
            cost += s[p[i].t].c*s[p[i].t].a;
            p[i].d -= s[p[i].t].a;
            s[p[i].t].a = 0;
            int fl=0;
            while(!st.empty())
            {
                st1 temp = st.top();
                temp.a = s[temp.ind].a; // update
                st.pop();
                if(temp.a >= p[i].d)
                {
                    temp.a -= p[i].d;
                    s[temp.ind].a = temp.a;
                    cost += p[i].d*temp.c;
                    if(temp.a!=0)   st.push(temp);
                    fl=1;
                    break;
                }
                else
                {
                    cost += temp.c*temp.a;
                    p[i].d -= temp.a;
                    s[temp.ind].a = 0;
                }
            }
            if(fl==1)
                cout<<cost<<"\n";
            else
               { cout<<"0\n";flag=1;}

        }
    }
    
}


