#include <bits/stdc++.h>
using namespace std;
struct st{
 int x,y,z;
};
bool comp (st a,st b)
{
    return (a.z==b.z) ? ((a.x == b.x) ? (a.y < b.y) : (a.x < b.x)) : (a.z < b.z); 
}
vector<st> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, kk;
    cin >> n >> m >> kk;
    char c;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            if (c == '.')
            {
                a[i][j] = 0;
            }
            else
            {
                a[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if(a[i][j]==0) continue;
            int k=1;
            while (i - k >= 0 && i + k < n && j - k >= 0 && j + k < m)
            {
                if(a[i-k][j]*a[i+k][j]*a[i][j+k]*a[i][j-k]==1)
                {
                    st temp;
                    temp.x = i+1;
                    temp.y = j+1;
                    temp.z = k;
                    v.push_back(temp);
                }
                k++;
            }
        }
    }
    sort(v.begin(),v.end(),comp);
    if(v.size() < kk)
    {
        cout<<-1;
        return 0;
    }
    int x = v[kk-1].x;
    int y = v[kk-1].y;
    int z = v[kk-1].z;
    cout<<x<<" "<<y<<"\n"<<x-z<<" "<<y<<"\n"<<x+z<<" "<<y<<"\n"<<x<<" "<<y-z<<"\n"<<x<<" "<<y+z;
}