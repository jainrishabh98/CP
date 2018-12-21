#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        int res[100000] = {0};
        int res_size = 1;
        res[0] = 1;
        int carry = 0;
        for (int i=2;i<=n;i++)
        {   
            // multiply res with i
            for (int j=0;j<res_size;j++)
            {
                int prod = (res[j] *i) + carry;
                res[j] = prod%10;
                carry = prod/10; 
            }
            while(carry)
            {
                res[res_size] = carry%10;
                res_size++;
                carry /= 10;
            }
        }
        for(int i = res_size-1;i>=0;i--)
            cout<<res[i];
        cout<<"\n";
    }

return 0;
}