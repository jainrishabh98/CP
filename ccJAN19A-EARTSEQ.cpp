#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
vector<int> primes;
void simpleSieve(int limit) 
{ 
    bool mark[limit+1]; 
    memset(mark, true, sizeof(mark)); 
  
    for (int p=2; p*p<limit; p++) 
    { 
        if (mark[p] == true) 
        { 
            for (int i=p*2; i<limit; i+=p) 
                mark[i] = false; 
        } 
    } 
  
    for (int p=2; p<limit; p++) 
    { 
        if (mark[p] == true) 
        { 
            prime.push_back(p); 
            primes.push_back(p);
            // cout << p << " "; 
        } 
    } 
} 
void segmentedSieve(int n) 
{ 
    
    int limit = floor(sqrt(n))+1;  
    simpleSieve(limit);  
    int low = limit; 
    int high = 2*limit; 
    while (low < n) 
    { 
        if (high >= n)  
           high = n; 
        bool mark[limit+1]; 
        memset(mark, true, sizeof(mark)); 
  
        for (int i = 0; i < prime.size(); i++) 
        {  
            int loLim = floor(low/prime[i]) * prime[i]; 
            if (loLim < low) 
                loLim += prime[i]; 
  
            for (int j=loLim; j<high; j+=prime[i]) 
                mark[j-low] = false; 
        } 

        for (int i = low; i<high; i++) 
            if (mark[i - low] == true) 
                primes.push_back(i);
  
        low = low + limit; 
        high = high + limit; 
    } 
} 
int main ()
{
    int t;
    cin>>t;
    segmentedSieve(611953);
    int y = 611953;
    while(t--)
    {
        int n;
        cin>>n;
        auto x = primes.begin();x++;x++;x++;x++;
        cout<<"55 ";int k=2,i;
        for(i=1;i<n-2;i++)
        {
            if(i%2!=0)
            {
                if(k==2) k=3;
                else k=2;
                cout<<(*x)*k<<" ";
                x++;
            }
            else
            {
                
                cout<<(*x)*k<<" ";
            }
        }
        i--;
        if(k==3 && i%2!=0)
        {
            cout<<(*x)*3<<" "<<(*x)*5<<"\n";
        }
        else if(i%2==0){
        // auto temp = x;
        // temp++;
        cout<<(*x)*7<<" "<<7*5<<"\n";
        }
        else{
            cout<<(*x)*2<<" "<<(*x)*5<<"\n";
        }
    }
    return 0;
}