#include<bits/stdc++.h>
using namespace std;
int main ()
{   
    float c;
    cin>>c;
    while(c!=0)
    {
        int cnt = 0;float temp = 2;
        while(c>0)
        {
            cnt++;
            c -= (1/temp);
            temp++;
        }
        cout<<cnt<<" card(s)\n";
        cin>>c;
    }
    return 0;
}