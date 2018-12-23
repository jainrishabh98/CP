#include<bits/stdc++.h>
using namespace std;
// all prime nos. except 2 and 3 are either (6K + 1) or (6K -1).This implies that p^p + 1 or p^p + 2 is/are prime only for 
// 2 & 3 (on taking p = 6K + 1 / 6K - 1)
int main ()
{   
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(a>3)
            cout<<"0\n";
        else
        {
            if(b>3) b = 3;
            int cnt = 0;
            for(int i = a;i<=b;i++)
                cnt++;
            cout<<cnt<<"\n";
        }
    }
    return 0;
}