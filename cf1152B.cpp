#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int t = 0;
    vector <int> b;
    while(true)
    {
        int x = n;
        int nb = 0,pos=0;
        while(x!=0)
        {
            nb++;
            if((x&1)==0)
                pos = nb;
            x /= 2;
        }
        if(pos==0)
            break;
        int temp = pow(2,pos) - 1;
        t++;
        b.push_back(pos);
        n = n^temp;
        if((n&(n+1))==0)
            break;
        t++;
        n++;
        if((n&(n+1))==0)
            break;
    }
    cout<<t;
    if(t!=0)
    {
        cout<<"\n";
        for(auto k:b)
            cout<<k<<" ";
    }
}