#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pii std::pair<int, int>
#define all(x) x.begin(), x.end()
using std::map, std::priority_queue, std::queue, std::set;
using std::stack, std::string, std::swap, std::unordered_map, std::unordered_set, std::vector;
int read(int x = 0, bool f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

int n, X, Y, ans;
pii A[N], B[N];
vector<int> U;
vector<pii> V;

struct Seg_Tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
    int max[N << 2], cnt[N << 2], laz[N << 2];
    void pushup(int p)
    {
        if (max[ls] == max[rs])
            cnt[p] = cnt[ls] + cnt[rs];
        else
            cnt[p] = max[ls] > max[rs] ? cnt[ls] : cnt[rs];
        max[p] = std::max(max[ls], max[rs]);
    }
    void pushdown(int p)
    {
        if (!laz[p])
            return;
        laz[ls] += laz[p], laz[rs] += laz[p];
        max[ls] += laz[p], max[rs] += laz[p];
        laz[p] = 0;
    }
    void build(int p, int l, int r)
    {
        laz[p] = 0;
        if (l == r)
            return max[p] = 0, cnt[p] = U[l + 1] - U[l], void();
        build(ls, l, mid), build(rs, mid + 1, r), pushup(p);
    }
    void modify(int p, int l, int r, int x, int y, int k)
    {
        if (l == x and r == y)
            return max[p] += k, laz[p] += k, void();
        pushdown(p);
        if (x <= mid)
            modify(ls, l, mid, x, std::min(mid, y), k);
        if (mid < y)
            modify(rs, mid + 1, r, std::max(mid + 1, x), y, k);
        pushup(p);
    }
} T;

int solve(pii A[], int X)
{
    U.clear(), V.clear(), U.pb(0), U.pb(X);
    for (int i = 1; i <= n; i++)
        U.pb(A[i].fi), U.pb(A[i].se);

    sort(all(U));
    U.erase(unique(all(U)), U.end());
    for (int i = 1; i <= n; i++)
        A[i].fi = lower_bound(all(U), A[i].fi) - U.begin(),
        A[i].se = lower_bound(all(U), A[i].se) - U.begin();
    X = lower_bound(all(U), X) - U.begin();
    int m = U.size() - 2;
    T.build(1, 0, m);
    for (int i = 1; i <= n; i++)
    {
        V.pb({A[i].fi, i}), V.pb({A[i].se, -i});
        T.modify(1, 0, m, 0, m, 1);
        T.modify(1, 0, m, A[i].fi, A[i].se - 1, -1);
    }
    std::sort(all(V));
    int res = 0, j = 0;
    for (int i = 0; i <= m; i++)
    {
        for (; j < V.size() and V[j].fi <= i; j++)
        {
            int idx = abs(V[j].se), f = V[j].se > 0 ? 1 : -1;
            T.modify(1, 0, m, 0, m, f * -1);
            T.modify(1, 0, m, A[idx].fi, A[idx].se - 1, f * 2);
        }
        res = std::max(res, T.cnt[1]);
    }
    return res;
}

signed main()
{
    n = read(), X = read(), Y = read();
    for (int i = 1; i <= n; i++)
    {
        int x1 = read(), y1 = read(), x2 = read(), y2 = read();
        A[i] = {std::min(x1, x2), std::max(x1, x2)};
        B[i] = {std::min(y1, y2), std::max(y1, y2)};
    }
    int ansX = solve(A, X), ansY = solve(B, Y);
    printf("%lld\n", ansX * ansY);
    return 0;
}