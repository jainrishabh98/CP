#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    set <int> s;
    int t;
    int cnt[1001]={0};
    for(int i=0;i<n;i++)
    {
        cin>>t;
        cnt[t]++;
        s.insert(t);
    }
    stack <int> st;
    for(auto i:s)
    {
        if(!st.empty())
        {
            int x = cnt[i];
            while(x-- && !st.empty())
            {
                st.pop();
            }
        }
        int x = cnt[i];
            while(x--)
            {
                st.push(i);
            }
    }
    long long int sum = 0;
    while(!st.empty())
    {
        sum += st.top();
        st.pop();
    }
    cout<<sum;


}