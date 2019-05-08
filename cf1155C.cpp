#include <iostream>
using namespace std;
long long gcc(long long a, long long b)
{
    if(b==0)
        return a;
    return gcc(b,a%b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    long long int x, y, st, gc = 0;
    cin >> x;
    st = x;
    for (int i = 1; i < n; i++)
    {
        cin >> y;
        gc = gcc(gc, y - x);
        x = y;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        if (gc % x == 0)
        {
            cout << "YES\n"
                 << st << " " << i;
            return 0;
        }
    }
    cout << "NO";
}