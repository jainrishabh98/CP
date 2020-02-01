#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int x1,y1,x2,y2,r1,r2;
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		long long int dist2=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
		if(r1>r2 || (dist2>(r2-r1)*(r2-r1))){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
			continue;
		}
		long double dist=sqrt((double)dist2);
		if(dist2==0){
			cout<<x1+r1<<" "<<y1<<endl;
		}
		else{
			cout<<setprecision(30)<<(x1*(dist+r1)-r1*x2)/dist;
	        cout<<" ";
	        cout<<setprecision(30)<<(y1*(dist+r1)-r1*y2)/dist<<endl;
		}
        
    }
}