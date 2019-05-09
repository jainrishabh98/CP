#include <bits/stdc++.h>
using namespace std;
int cnt[100005];
int cn[100005];
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mx = 0;
    int cc = 0;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        cnt[a[i]]++;
        cn[cnt[a[i]]]++;
        mx = max(mx,cnt[a[i]]);
        if((cn[mx]==1 && cn[mx-1]==cn[1]) || mx==1 || (cn[mx]==(cn[1]-1) && cn[2]<cn[1]))
        {
            x = i+1;
        }
    }
    cout<<x;
}