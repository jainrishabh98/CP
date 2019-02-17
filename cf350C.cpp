#include<bits/stdc++.h>
using namespace std;
struct st{
    int x,y;
};
bool comp(st a, st b)
{
    return (abs(a.y)==abs(b.y)) ? (abs(a.x)<abs(b.x)) : (abs(a.y)<abs(b.y));
}
int main ()
{
    int n;
    cin>>n;
    st points[n];
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        cin>>points[i].x>>points[i].y;
        if(points[i].x==0 || points[i].y==0)
        {
            cnt++;
        }
    }
    sort(points,points+n,comp);
    cout<<n*6 - cnt*2<<"\n";
    for(int i=0;i<n;i++)
    {
        int x = points[i].x,y = points[i].y;
        if(x>=0 && y>=0)
        {   
            if(x!=0)
            cout<<"1 "<<abs(x)<<" R\n";
            if(y!=0)
            cout<<"1 "<<abs(y)<<" U\n";
            cout<<"2\n";
            if(y!=0)
            cout<<"1 "<<abs(y)<<" D\n";
            if(x!=0)
            cout<<"1 "<<abs(x)<<" L\n";
            cout<<"3\n";
        }
        else if(x<=0 && y>=0)
        {
            if(x!=0)
            cout<<"1 "<<abs(x)<<" L\n";
            if(y!=0)
            cout<<"1 "<<abs(y)<<" U\n";
            cout<<"2\n";
            if(y!=0)
            cout<<"1 "<<abs(y)<<" D\n";
            if(x!=0)
            cout<<"1 "<<abs(x)<<" R\n";
            cout<<"3\n";
        }
        else if(x>=0 && y<=0)
        {
            if(x!=0)
            cout<<"1 "<<abs(x)<<" R\n";
            if(y!=0)
            cout<<"1 "<<abs(y)<<" D\n";
            cout<<"2\n";
            if(y!=0)
            cout<<"1 "<<abs(y)<<" U\n";
            if(x!=0)
            cout<<"1 "<<abs(x)<<" L\n";
            cout<<"3\n";
        }
        else if(x<=0 && y<=0)
        {
            if(x!=0)
            cout<<"1 "<<abs(x)<<" L\n";
            if(y!=0)
            cout<<"1 "<<abs(y)<<" D\n";
            cout<<"2\n";
            if(y!=0)
            cout<<"1 "<<abs(y)<<" U\n";
            if(x!=0)
            cout<<"1 "<<abs(x)<<" R\n";
            cout<<"3\n";
        }
    }
}