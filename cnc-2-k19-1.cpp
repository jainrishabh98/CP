#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x;
        int al=0,d=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(i%2==0)
            {
                if(x<4)
                    al += 2;
                else
                    d += 1;
            }
            else
            {
                if(x > 3)
                    d += 2;
                else
                    al += 1;
            }
        }
        if(al==d)
            cout<<"Draw\n";
        else if(al > d)
            cout<<"Alice\n";
        else 
            cout<<"Bob\n";
    }
}