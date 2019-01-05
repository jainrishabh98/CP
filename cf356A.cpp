#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n,m;
    cin>>n>>m;
    int a[n+1]={0};
    int l,r,x;
    set <int> v;
    for(int i=1;i<=n;i++)
        v.insert(i);
    for(int i=0;i<m;i++)
       { cin>>l>>r>>x;
        set<int>::iterator it = v.lower_bound(l);
        vector<int> toErase;        
        while(it != v.end()){
            int cur = *it;            
            if(cur > r)
                break;                
            if(cur != x){    
                toErase.push_back(cur); a[cur] = x;
            }
            it++;
        }
        for (size_t j = 0; j < toErase.size(); j++)
            v.erase(toErase[j]);
        
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}