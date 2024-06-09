#include <bits/stdc++.h>
// #define int long long
using pii = std::pair<int, int>;
using std::vector, std::cout, std::cin;
#define fi first
#define se second
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid (l + r >> 1)
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int RANDOM = std::chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { int operator()(int x) const { return x ^ RANDOM; } };
typedef gp_hash_table<int, int, chash> hash_t;
*/


const int N = 3e5 + 5;
long long sum[N << 2];
// hash_t t[N << 2];
std::unordered_map<int, int> t[N << 2];
void modifyC(int p, int l, int r, int pos, int col, int val)
{
    t[p][col] += val;
    if (l == r) return;
    if (pos <= mid) modifyC(ls, l, mid, pos, col, val);
    else modifyC(rs, mid + 1, r, pos, col, val);
}
void modifyS(int p, int l, int r, int pos, int val)
{
    if (l == r) return sum[p] += val, void();
    if (pos <= mid) modifyS(ls, l, mid, pos, val);
    else modifyS(rs, mid + 1, r, pos, val);
    sum[p] = sum[ls] + sum[rs];
}
bool check(int p, int l, int r, vector<int> &A)
{
    int res = 0;
    for (auto col : A) res += t[p][col];
    return res == r - l + 1;
}
int queryCL(int p, int l, int r, int pos, vector<int> &A)
{
    if (l > pos) return -1;
    if (r <= pos)
    {
        if (check(p, l, r, A)) return -1;
        if (l == r) return l + 1;
    }
    int res = queryCL(rs, mid + 1, r, pos, A);
    if (res != -1) return res;
    return queryCL(ls, l, mid, pos, A);
}
int queryCR(int p, int l, int r, int pos, vector<int> &A)
{
    if (r < pos) return -1;
    if (l >= pos)
    {
        if (check(p, l, r, A)) return -1;
        if (l == r) return l - 1;
    }
    int res = queryCR(ls, l, mid, pos, A);
    if (res != -1) return res;
    return queryCR(rs, mid + 1, r, pos, A);
}
long long queryS(int p, int l, int r, int ql, int qr)
{
    if (ql <= l and r <= qr) return sum[p];
    long long res = 0;
    if (ql <= mid) res += queryS(ls, l, mid, ql, qr);
    if (mid < qr) res += queryS(rs, mid + 1, r, ql, qr);
    return res;
}
void solve()
{
    int n = read(), q = read();
    vector<int> c(n + 1), v(n + 1);
    for (int i = 1; i <= n * 4; i++) t[i].clear();
    memset(sum, 0, sizeof(long long) * (4 * n + 1));
    for (int i = 1; i <= n; i++)
        c[i] = read(), modifyC(1, 1, n, i, c[i], 1);
    for (int i = 1; i <= n; i++)
        v[i] = read(), modifyS(1, 1, n, i, v[i]);
    for (int opt, x, y; q--; )
    {
        opt = read(), x = read(), y = read();
        if (opt == 1)
            modifyC(1, 1, n, x, c[x], -1),
            c[x] = y,
            modifyC(1, 1, n, x, c[x], +1);
        if (opt == 2)
            modifyS(1, 1, n, x, y - v[x]), v[x] = y;
        if (opt == 3)
        {
            bool f = false;
            vector<int> A(y, 0);
            for (auto &z : A) f |= (c[x] == (z = read()));
            if (!f) { puts("0"); continue; }
            int l = queryCL(1, 1, n, x, A);
            int r = queryCR(1, 1, n, x, A);
            l = l == -1 ? 1 : l;
            r = r == -1 ? n : r;
            cout << queryS(1, 1, n, l, r) << '\n';
        }
    }
    // for (int i = 1; i <= 4 * n; ++i) t[i].clear(), sum[i] = 0;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("F.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}