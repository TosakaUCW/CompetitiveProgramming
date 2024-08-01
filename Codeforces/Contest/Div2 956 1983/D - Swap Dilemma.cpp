#include <bits/stdc++.h>
using i64 = long long;
#define int long long
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;
int n, max, tim, c[N], ts[N];

int lowbit(int x) { return x & -x; }
void upd(int x, int v) 
{
    for (; x <= max; x += lowbit(x))
    {
        if (ts[x] != tim) ts[x] = tim, c[x] = 0;
        c[x] += v;
    }
}
i64 query(int x) 
{
    i64 res = 0;
    for (; x; x -= lowbit(x)) if (ts[x] == tim) res += c[x];
    return res;
}

void solve()
{
    n = read();
    std::vector<int> a(n + 1), b(n + 1);
    max = 0;
    
    for (int i = 1; i <= n; i++) a[i] = read(), max = std::max(max, a[i]);
    for (int i = 1; i <= n; i++) b[i] = read(), max = std::max(max, b[i]);
    
    tim++;
    
    i64 ansA = 0, ansB = 0;
    for (int i = n; i >= 1; i--)
        ansA += query(a[i] - 1), upd(a[i], 1);
        
    tim++;
    
    for (int i = n; i >= 1; i--)
        ansB += query(b[i] - 1), upd(b[i], 1);
    
    std::sort(a.begin() + 1, a.end());
    std::sort(b.begin() + 1, b.end());
    for (int i = 1; i <= n; i++) 
        if (a[i] != b[i])
            return puts("NO"), void();
            
    puts((ansA - ansB) % 2 == 0 ? "YES" : "NO");
}
/*
3 1 2 4 5 7
2

1 3 2 7 5 4
1 + 2 + 1 = 4
*/

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}