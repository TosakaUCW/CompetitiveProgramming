#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
#define ins insert
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int INF = 2e9;

void solve()
{
    int n = read();
    vector<int> a(n + 2);
    a[0] = -INF, a[n + 1] = INF;
    for (int i = 1; i <= n; i++) a[i] = read();
    std::multiset<int> s, s1, s2;
    for (int i = 1; i <= n; i++)
        if (a[i - 1] > a[i])
            s.ins(i - 1), s1.ins(a[i - 1]), s2.ins(a[i]);
            
    auto add = [&](int x)
    {
        if (a[x - 1] > a[x])
            s.ins(x - 1), 
            s1.ins(a[x - 1]), 
            s2.ins(a[x]);
        if (a[x] > a[x + 1])
            s.ins(x), 
            s1.ins(a[x]), 
            s2.ins(a[x + 1]);
    };
    auto del = [&](int x)
    {
        if (a[x - 1] > a[x])
            s.erase(x - 1), 
            s1.erase(s1.find(a[x - 1])), 
            s2.erase(s2.find(a[x]));
        if (a[x] > a[x + 1])
            s.erase(x),
            s1.erase(s1.find(a[x])), 
            s2.erase(s2.find(a[x + 1]));
    };
    // 1 2 [1 x x] 6 7 8 9 10
    //   L      R 
    auto query = [&]()
    {
        if (s.empty()) return puts("-1 -1"), void();
        
        int L = *s.begin();
        int R = *s.rbegin() + 1;
        
        int min = *s2.begin();
        int max = *s1.rbegin();
        
        // printf("[%d %d]\n", L, R);
        
        int ansL = 1, ansR = n;
        for (int l = 1, r = L; l <= r; )
        {
            int mid = l + r >> 1;
            if (min < a[mid]) ansL = mid, r = mid - 1;
            else l = mid + 1;
        }
        for (int l = R, r = n; l <= r; )
        {
            int mid = l + r >> 1;
            if (a[mid] < max) ansR = mid, l = mid + 1;
            else r = mid - 1;
        }
        
        cout << ansL << ' ' << ansR << '\n';
    };
    
    
    query();
    for (int q = read(); q--; )
    {
        int x = read(), y = read();
        del(x), a[x] = y, add(x);
        query();
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}