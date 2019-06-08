#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int col1 = 0,col2 = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            cout<<col1;
            col1 = col1^1;
        }
        else
        {
            cout<<col2;
            col2 = col2^1;
        }
        
    }
}