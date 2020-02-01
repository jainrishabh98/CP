#include<bits/stdc++.h>
using namespace std;
struct trie{
    int cnt;
    unordered_map<char,trie*> child;
    trie(){cnt = 0;}
};
trie* root = new trie;
void insert(string s)
{
    trie* trav = root;
    for(int i=0;i<s.length();i++)
    {
        if(trav->child.find(s[i])==trav->child.end())
            trav->child[s[i]] = new trie;
        trav = trav->child[s[i]];
        trav->cnt++;
    }
}
int search(string s)
{
    trie* trav = root;
    for(int i=0;i<s.length();i++)
    {
        if(trav->child.find(s[i])==trav->child.end())
            return 0;
        trav = trav->child[s[i]];
    }
    return trav->cnt;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    string ss;
    for(int i=0;i<n;i++)
    {
        cin>>ss;
        insert(ss);
    }
    while(q--)
    {
        cin>>ss;
        cout<<search(ss)<<"\n";
    }
}