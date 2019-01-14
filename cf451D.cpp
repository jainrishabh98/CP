#include<bits/stdc++.h>
using namespace std;
int main ()
{
    string s;
    cin>>s;
    int n= s.length();
    int ce = 0;
    int co = 0;
    int fla=0,flb=0,cnt=0,cn=0;
    for(int i=0;i<n;)
    {
        if(s[i]=='a')
        {   if(fla==1 && flb==1) {cnt++;co += cnt;}
            int fl=1;i++;
            while(s[i]=='a' && i<n)
            {
                fl++;
                if(fla==1 && flb==1) 
                {
                    if(i%2==0) co += cnt;    // indexing is 0 based
                    else ce += cnt;
                }
                i++;
            }
            if(fl%2==0)
            {
                co += ((fl+2)*fl)/4; ce += (fl*fl)/4;
            }
            else
            {
               co += ((fl+1)*(fl+1))/4; ce += ((fl-1)*(fl+1))/4;
            }
            if(fla==0) fla=1;
            // cout<<ce<<" "<<co<<"\n";
        }
        else
        {   if(fla==1 && flb==1) {cn++;co += cn;}
            int fl=1;i++;
            while(s[i]=='b' && i<n)
            {
                fl++;
                if(fla==1 && flb==1) 
                {
                    if(i%2==0) co += cn; // indexing is 0 based
                    else ce += cn;
                }
                i++;
                // cout<<fl<<" "<<ce<<" "<<co<<"\n";
            }
            if(fl%2==0)
            {
                co += ((fl+2)*fl)/4; ce += (fl*fl)/4;
            }
            else
            {
                co += ((fl+1)*(fl+1))/4; ce += ((fl-1)*(fl+1))/4;
            }
            if(flb==0) flb=1;
            // cout<<ce<<" "<<co<<"\n";
        }
    }
    cout<<ce<<" "<<co<<"\n";
    return 0;
}