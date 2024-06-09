#include <bits/stdc++.h>
#define ins insert
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 3e5 + 5;
int n, a[N], d[N];

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) d[i] = read();
    d[0] = d[n + 1] = INT32_MAX, a[0] = a[n + 1] = 0;
    std::set<int> lft, cur;
    for (int i = 0; i <= n + 1; i++) lft.ins(i), cur.ins(i);
    for (; n--; )
    {
        std::set<int> del, ncur;
        for (int i : cur)
        {
            auto it = lft.find(i);
            if (it == lft.end()) continue;
            int L = *std::prev(it);
            int R = *std::next(it);
            if (a[L] + a[R] > d[i]) del.ins(i), ncur.ins(L), ncur.ins(R);
        }
        std::cout << del.size() << ' ';
        for (auto it : del) lft.erase(it);
        cur = ncur;
    }
    puts("");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}