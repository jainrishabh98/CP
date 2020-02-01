#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> v;
        v.push_back(0);
        int i = 1;
        while(true)
        {
            int t = n/i;
            int p = n/t;
            v.push_back(p);
            if(p==n)
                break;
            i = p+1;
        }
        cout<<v.size()<<"\n";
        for(auto j:v)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}