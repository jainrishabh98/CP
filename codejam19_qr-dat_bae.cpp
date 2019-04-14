#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        int n, b, f;
        string s[5],a[5];
        cin >> n >> b >> f;
        int in = 0;
        int fl = 0;
        while(true)
        {
        int flag=0;
        for(int i=1;i<=n;i+=b)
        {
            for(int k=i;k<=min(n,i+b-1);k++)
            {
                a[in].push_back((char)(flag + '0'));
            }
            flag = flag^1;
        }
        cout<<a[in]<<endl;   
        cin>>s[in];
        in++;
        if(b==1)
            break;
        if(b%2!=0) b++;
        b /= 2;
        }
        set <int> ans;
        int k=0;
        for(int i=0;i<n;i++)
        {
            int temp = 0;
            for(int inn=0;inn<in;inn++)
            {
                if(a[inn][i]!=s[inn][k])
                {
                    temp = 1;
                }
            }
            if(temp==1) 
                ans.insert(i);
            else
                k++;
        }
        for(auto pp:ans)
            cout<<pp<<" ";
        cout<<endl;
        cin>>k;
        if(k==-1)
            return 0;
    }
}