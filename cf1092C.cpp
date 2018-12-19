#include<bits/stdc++.h>
// someone else's solution
using namespace std;
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define MOD 998244353
#define MAXN 300005
unordered_map<int, vector<pair<string,int> > > M;

char ans[505];

int main()
{
	int n; cin>>n; string s;
	for(int i=0;i<2*n - 2; ++i)
	{
		cin>>s;
		M[s.length()].pb(mp(s,i));
	}
	ans[M[n-1][0].second] = 'P';
	ans[M[n-1][1].second] = 'S';
	bool justdoit = false;
	for(int i=n-2;i>0;--i)
	{
		if(M[i][0].first == M[n-1][0].first.substr(0,i))
		{
			ans[M[i][0].second] = 'P';
			ans[M[i][1].second] = 'S';
		}
		else if(M[i][1].first == M[n-1][0].first.substr(0,i))
		{
			ans[M[i][0].second] = 'S';
			ans[M[i][1].second] = 'P';
		}
		else
		{
			justdoit = true;
			break;
		}
	}
	for(int i=n-2;i>0;--i)
	{
	    string str1 = M[n-1][0].first.substr(n-1-i,i);
    	if(ans[M[1][0].second] == 'S')
    	    str1 = str1.append(M[1][0].first);
    	else
    	    str1 = str1.append(M[1][1].first);
    	if(ans[M[i+1][1].second] == 'S' && str1 != M[i+1][1].first)
    	{
    	    justdoit = true;
    	    // cout<<str1<<" "<<M[n-1][1].first<<endl;
    	    break;
    	}
    	else if(ans[M[i+1][0].second] == 'S' && str1 != M[i+1][0].first)
    	{
    	    justdoit = true;
    	    // cout<<str1<<" "<<M[n-1][1].first<<endl;
    	    break;
    	}
	}
	if(!justdoit)
	{
		for(int i=0;i<2*n - 2;++i) cout<<ans[i];
		return 0;
	}
	ans[M[n-1][0].second] = 'S';
	ans[M[n-1][1].second] = 'P';
	for(int i=n-2;i>0;--i)
	{
		if(M[i][0].first == M[n-1][1].first.substr(0,i))
		{
			ans[M[i][0].second] = 'P';
			ans[M[i][1].second] = 'S';
		}
		else
		{
			ans[M[i][0].second] = 'S';
			ans[M[i][1].second] = 'P';
		}
	}
	for(int i=0;i<2*n - 2;++i) cout<<ans[i];
	return 0;
}