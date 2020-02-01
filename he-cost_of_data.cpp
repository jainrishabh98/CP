#include<bits/stdc++.h>
using namespace std;
struct trie{
    unordered_map<char,trie*> child;
};
trie* root = new trie;
int cnt = 1;
void insert(string s)
{
    trie* trav = root;
    for(int i=0;i<s.length();i++)
    {
        if(trav->child.find(s[i])==trav->child.end())
            {trav->child[s[i]] = new trie;cnt++;}
        trav = trav->child[s[i]];
    }
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string ss;
    for(int i=0;i<n;i++)
    {
        cin>>ss;
        insert(ss);
    }
    cout<<cnt;
}