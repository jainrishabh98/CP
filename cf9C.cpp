#include <bits/stdc++.h>
using namespace std;
int main()
{
    string n;
    cin >> n;
    int m = n.length();
    if (n[0] - (int)'0' > 1)
    {
        cout << pow(2, m) - 1;
        return 0;
    }
    long long int ans = pow(2, m - 1) - 1;
    long long int cnt, an = 0, fl = 0;
    if(n[m-1]-'0' <=1)
        n[m-1] = n[m-1] + 1;
    for (int i = 1; i < m; i++)
    {

        if (n[i] - (int)'0' > 1)
        {
            an += (2*pow(2,m-i-1));
            break;
        }
        else if (n[i] - (int)'0' == 1)
        {
            an += pow(2,m-i-1);
        }
        else
            continue;
        // cout<<an<<"\n";
        
    }
    // cout << ans << " " << an << "\n";
    cout << max((long long)1,an) + ans;
}