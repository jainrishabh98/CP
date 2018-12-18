#include<bits/stdc++.h>
using namespace std;
int main ()
{   int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int f = n/k;
        n = n-(f*k);
        for (int i=0;i<k;i++)
        {
            for(int j=0;j<f;j++)
            {
                cout<<(char)(i+97);
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<'a';
        }
        cout<<"\n";
    }
    return 0;
}