#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long int t,a,b,xl,yl,xu,yu,m=1e9;
    cin>>t;
    while(t--)
    {
        cout<<"Q 0 0"<<endl;
        cin>>a;
        cout<<"Q 1000000000 0"<<endl;
        cin>>b;
        cout<<"Q "<<(abs(a-b+m))/2<<" 0"<<endl;
        cin>>yl;
        xl = a - yl;
        xu = m + yl - b;
        cout<<"Q "<<m<<" "<<m<<endl;
        cin>>a;
        yu = 2*m - xu - a;
        cout<<"A "<<xl<<" "<<yl<<" "<<xu<<" "<<yu<<endl;
        cin>>a;
        if(a<0) return 0;
    }
}