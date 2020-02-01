#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (n == 0)
            cout << "Bob\n";
        else if(n==k)
            cout<<"Alice\n";
        else if (n % 3 != 0 && (k % 3 != 0 || k > n))
            cout << "Alice\n";
        else if (k % 3 != 0 || k>n)
            cout << "Bob\n";
        else
        {
            n = n%(k+1);
            if (n % 3 != 0 || n==k)
                cout << "Alice\n";
            else
                cout << "Bob\n";
        }
    }
}