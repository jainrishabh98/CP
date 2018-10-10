#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int c[n];
    char s[n][4];
    int fl1 =0 , fl2 =0, fl3 =0;
    for(int i=0;i<n;i++)
        {cin>>c[i];
         cin>>s[i];
         for(int j =0; j< strlen(s[i]); j++)
            {
                if(s[i][j]=='A')
                    fl1=1;
                else if(s[i][j]=='B')
                    fl2=1;
                else
                    fl3=1;
            }
        sort(s[i],s[i]+strlen(s[i]));
        }
    if(fl1 == 1 && fl2==1 && fl3==1)
    {
        
    }
    else
        cout<<"-1\n";
    return 0;
}
    
