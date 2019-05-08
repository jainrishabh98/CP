#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int pos = n-1;
    for(int i=n-2;i>=0;i--)
    {
        if(s[i] > s[pos])
        {
            cout<<"YES\n"<<i+1<<" "<<pos+1;
            return 0;
        }
        else
        {
            pos = i;
        }
    }
    cout<<"NO";
}