#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    if(n%2==0)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES\n";
        int x = 1,y=4;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                cout<<x<<" ";
                v.push_back(x + 1);
                x += 4;
            }
            else
            {
                cout<<y<<" ";
                v.push_back(y-1);
                y += 4;
            }
        }
        for(auto i:v)
        {
            cout<<i<<" ";
        }
    }
}