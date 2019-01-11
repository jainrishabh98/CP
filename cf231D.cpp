#include<bits/stdc++.h>
using namespace std;
int main ()
{ int x,y,z,x1,y1,z1;
  int a[6];
  cin>>x>>y>>z>>x1>>y1>>z1;
  cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
  int ans=0;
  if(x>x1)
    ans += a[5];
  if(x<0)
    ans += a[4];
  if(z<0)
    ans += a[2];
  if(z>z1)
    ans += a[3];
  if(y<0)
    ans += a[0];
  if(y>y1)
    ans += a[1];
   cout<<ans<<"\n";
   return 0;
}