def check(x):
    if (x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u'):
        return True
    return False

t = input()
for p in range(1,t):
    l = input()
    v1 = []
    v2 = []
    for k in range(1,l):
        s = input()
        fl = 0
        for j in range(0,len(s)):
            if (check(s[j])==False):
                if ((check(s[j + 1])==False) or (j + 2 < len(s) and (check(s[j + 2])==False))):
                        fl = 1
                        break
            if (fl == 0):
                v1.append(s)
            else:
                v2.append(s)
    n = v1.size()
    m = v2.size()
    fxa[26] = {0}
    xa[26] = {0}
    for i in range(0,n):
        s = v1[i]
        set<int> ss
        for j in range(0,len(s)):
            fxa[s[j]-'a']++;
            ss.insert(s[j]-'a');
        for(auto j:ss):
            xa[j]++;
        ll fxb[26] = {0};
        ll xb[26] = {0};
        for(int i=0;i<m;i++)
        {
            s = v2[i];
            set<int> ss;
            for(int j=0;j<s.length();j++)
            {
                fxb[s[j]-'a']++;
                ss.insert(s[j]-'a');
            }
            for(auto j:ss)
            {
                xb[j]++;
            }
        }
        long double p1 = 1,p2 = 1;
