#include<bits/stdc++.h>
using namespace std;
// for n = even => board is symmetric => wherever A places a corresponding symmetric place is available for B everytime till A can't place
// for n = odd => board is having 1 point (which is at the centre) which is having no symmetric point. A places there and then 
// wherver B places a corresponding symmetric place is available for A everytime till B can't place
int main ()
{  int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       if(n%2==0)
            cout<<"1\n";
        else
            cout<<"0\n";
   }
   return 0;
}
