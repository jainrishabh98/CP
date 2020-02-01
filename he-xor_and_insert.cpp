#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct trie
{
    trie *mp[2];
    trie(){mp[0] = NULL;mp[1] = NULL;}
};
trie *root = new trie;
ll pre_xor = 0;
void insert(vector<int> v)
{
    trie* temp = root;
    for (auto i : v)
    {
        if (!temp->mp[i])
            temp->mp[i] = new trie;
        temp = temp->mp[i];
    }
}
vector <int> find_min(vector<int> v)
{
    trie *temp = root;
    vector<int> vv;
    for (auto i : v)
    {
        if (temp->mp[i])
        {
            vv.push_back(i);
            temp = temp->mp[i];
        }
        else
        {
            vv.push_back(i^1);
            temp = temp->mp[i^1];
        }
    }
    return vv;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector <int> vvv;
    for(int i=0;i<=31;i++)
    {
        vvv.push_back(0);
    }
    insert(vvv);
    ll q, t, x;
    cin >> q;
    while (q--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> x;
            x ^= pre_xor;
            vector<int> v;
            if (x == 0)
                v.push_back(0);
            while (x != 0)
            {
                if (x % 2 == 0)
                    v.push_back(0);
                else
                    v.push_back(1);
                x /= 2;
            }
            int l = v.size();
            for (int i = 1; i <= 32 - l; i++)
                v.push_back(0);
            reverse(v.begin(), v.end());
            insert(v);
        }
        else if (t == 2)
        {
            cin >> x;
            pre_xor ^= x;
        }
        else
        {
            x = pre_xor;
            vector<int> v;
            if (x == 0)
                v.push_back(0);
            while (x != 0)
            {
                if (x % 2 == 0)
                    v.push_back(0);
                else
                    v.push_back(1);
                x /= 2;
            }
            int l = v.size();
            for (int i = 1; i <= 32 - l; i++)
                v.push_back(0);
            reverse(v.begin(), v.end());
            vvv = find_min(v);
            reverse(vvv.begin(),vvv.end());
            ll p = 1,xx = 0;
            for(auto i: vvv)
            {
                xx = xx + p*i;
                p *= 2;
            }
            xx ^= pre_xor;
            cout<<xx<<"\n";
        }
    }
}