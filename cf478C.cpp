#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int v[3], a, c=0,b,n;
    cin >> v[0] >> v[1] >> v[2];
    sort(v, v + 3);
    if(v[2] >= 2*(v[0] + v[1]))
        c = v[0] + v[1];
    else
        c = (v[0] + v[1] + v[2])/3;
    cout<<c;
}