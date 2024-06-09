#include <bits/stdc++.h>
// #define int long long
#define fi first
#define se second
#define ins insert
#define pb push_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
using std::list;
using std::map;
using std::priority_queue;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::swap;
using std::unordered_map;
using std::unordered_set;
using std::vector;
int read(int x = 0, bool f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
int pow(int x, int k, int P, int res = 1)
{
    for (; k; k >>= 1, x = x * x % P)
        if (k & 1)
            res = res * x % P;
    return res;
}

const int N = 1e6 + 5;
const int P = 998244353;

int T, n;
vector<pii> a;

auto pre(auto it) { return --it; }

bool solve2(list<pii> &s)
{
    if (s.size() == 2)
        return 0;
    auto g = --s.end(), f = s.begin(), r = ++s.begin();
    pii k(g->fi - f->fi, g->se);
    if (k > *r)
        return 0;
    else
        return s.erase(g), *f = k, !solve2(s);
}

int solve1(list<pii> &s, auto it)
{
    if (s.size() == 2)
        return 1;
    auto g = --s.end(), f = s.begin(), r = ++s.begin();
    pii k(g->fi - f->fi, g->se);
    if (k > *r)
    {
        if (it == f)
            ++it;
        s.erase(f);
        if (it == g)
            ++it;
        s.erase(g);
        while (it != s.begin() and *pre(it) > k)
            --it;
        s.insert(it, k);
        return solve1(s, it);
    }
    else
        return s.erase(g), *f = k, s.size() + 1 - solve2(s);
}

void solve()
{
    list<pii> s(a.begin(), a.end());
    printf("%d\n", solve1(s, s.end()));
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("my_input.in", "r", stdin);
#endif

    T = read(), n = read(), a.resize(n);
    for (int i = 0; i < n; i++)
        a[i] = {read(), i + 1};
    for (solve(); --T; solve())
        for (int k = read(), x; k--;)
            x = read(), a[x - 1].fi = read();

#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
    return 0;
}
