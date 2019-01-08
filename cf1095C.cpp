#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    int m=n;
    while (n >= 1)
    {

        v.push_back(n & (-n));
        n -= (n & (-n));
    }
    if (v.size() > k || k>m)
    {
        cout << "NO\n";
    }
    else
    {
        int cnt = v.size();
        int pntr;
        while(cnt!=k)
        { pntr = v.size()-1;
        while(cnt!=k && pntr>=0)
        {   
            while(v[pntr]!=1  && cnt!=k)
            {   
                v[pntr] /= 2;
                // cout<<v[pntr]<<" ";
                v.push_back(v[pntr]);
                cnt++;
            }
            // cout<<"\n";
            pntr--;
        }
        // cout<<'h';
        }
            cout<<"YES\n";
            for(int i=0;i<cnt;i++)
                cout<<v[i]<<" ";
            cout<<"\n";
        
    }
}