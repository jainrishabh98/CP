#include<bits/stdc++.h>
using namespace std;
struct st{
    int val;
    int in;
};
bool comp(st a, st b)
{
    return(a.val < b.val);
}
int main ()
{
    int n;
    cin>>n;
    st s[n+1];
    for(int i=1;i<=n;i++)
        {cin>>s[i].val;
         s[i].in = i;
        }
    sort(s+1,s+n+1,comp);
    int cnt =0, i=1;
    while(s[i].val<0 && i<=n)
    {
        cnt++;
        i++;
    }
    i=1;
    int final_index = s[n].in;
    if((s[1].val==0 && s[n].val==0) || (s[n].val==0 && cnt==1))
    {
        for(int i=1;i<n;i++)
        {
            cout<<"1 "<<s[i].in<<" "<<final_index<<"\n";
        }
        return 0;

    }
    if(s[n].val<=0 && cnt>1)
        final_index = s[1].in;
    vector <int> store;
    i = n;
        while(s[i].val>0 && i>=1)
        {   if(s[i].in == final_index)
                {
                    i--;
                }
            else{
                cout<<"1 "<<s[i].in<<" "<<final_index<<"\n";
                i--;
            }
            
        }
        while(s[i].val==0 && i>=1)
        {
            store.push_back(s[i].in);
            i--;
        }
        if((cnt&1)==0)
        {
            while(i>=1)
            {
                if(s[i].in == final_index)
                {
                    i--;
                }
                else{
                cout<<"1 "<<s[i].in<<" "<<final_index<<"\n";
                i--;
                }
            }
        }
        else
        {   
            store.push_back(s[i].in);
            i--;
            while(i>=1)
            {
                if(s[i].in == final_index)
                {
                    i--;
                }
                else{
                cout<<"1 "<<s[i].in<<" "<<final_index<<"\n";
                i--;
                }
            }
            
           
        }
    
    if(!store.empty())
    {   int index = store.back();
        store.pop_back();
        while(!store.empty())
        {
            cout<<"1 "<<store.back()<<" "<<index<<"\n";
            store.pop_back();
        }
        cout<<"2 "<<index<<"\n";
        
    }
        
    return 0;
}
    