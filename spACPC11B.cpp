#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{	vector <pair<int,int> > v;

		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{ int x;cin>>x;v.push_back(make_pair(x,1));}
		cin>>n;
		for(int i=0;i<n;i++)
		{ int x;cin>>x;v.push_back(make_pair(x,2));}
		sort(v.begin(),v.end());
		int mn = INT_MAX;
		vector <pair<int,int> > :: iterator j = v.begin();
		j++;
		for(;j!=v.end();j++)
		{
			vector <pair<int,int> > :: iterator k = j;
			k--;
			if(j->second != k->second)
				mn = min(mn,abs(j->first - k->first));
		}
		cout<<mn<<"\n";
	}
	return 0;
}
		