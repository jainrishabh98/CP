#include<bits/stdc++.h>
using namespace std;
struct trie{
    bool end;
    unordered_map<char,trie*> child;
    trie(){end = false;}
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
    }
    trav->end = true;
}
bool search(string s)
{
    trie* trav = root;
    for(int i=0;i<s.length();i++)
    {
        if(trav->child.find(s[i])==trav->child.end())
            return false;
        trav = trav->child[s[i]];
    }
    return trav->end;
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
    int q;
    cin>>q;
    while(q--)
    {
        cin>>ss;
        cout<<search(ss)<<"\n";
    }
}