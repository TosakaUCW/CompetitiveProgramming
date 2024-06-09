#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 1e5 + 5;

int n, m, P;
int a[N];

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

struct Segment_Tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) / 2)
    int sum[N << 2], add[N << 2], mul[N << 2];
    void push_down(int p, int l, int r)
    {
        ((sum[ls] *= mul[p]) += (add[p] * (mid - l + 1))) %= P;
        ((sum[rs] *= mul[p]) += (add[p] * (r - mid))) %= P;
        (mul[ls] *= mul[p]) %= P, (mul[rs] *= mul[p]) %= P;
        ((add[ls] *= mul[p] %= P) += add[p]) %= P, ((add[rs] *= mul[p] %= P) += add[p]) %= P;
        mul[p] = 1, add[p] = 0;
    }
    void push_up(int p) { sum[p] = (sum[ls] + sum[rs]) % P; }
    void build(int p, int l, int r)
    {
        mul[p] = 1;
        if (l == r)
        {
            sum[p] = a[l] % P;
            return;
        }
        build(ls, l, mid), build(rs, mid + 1, r), push_up(p);
    }
    void modify(int p, int l, int r, int x, int y, int k, int opt)
    {
        if (l == x and r == y)
        {
            if (opt)
                (sum[p] += k * (r - l + 1)) %= P, (add[p] += k) %= P;
            else
                (sum[p] *= k) %= P, (mul[p] *= k) %= P, (add[p] *= k) %= P;
            return;
        }
        push_down(p, l, r);
        if (x <= mid)
            modify(ls, l, mid, x, std::min(mid, y), k, opt);
        if (mid < y)
            modify(rs, mid + 1, r, std::max(mid + 1, x), y, k, opt);
        push_up(p);
    }
    int query(int p, int l, int r, int x, int y)
    {
        if (l == x and r == y)
            return sum[p];
        int res = 0;
        push_down(p, l, r);
        if (x <= mid)
            (res += query(ls, l, mid, x, std::min(mid, y))) %= P;
        if (mid < y)
            (res += query(rs, mid + 1, r, std::max(mid + 1, x), y)) %= P;
        return res;
    }

} T;

signed main()
{
    n = read(), P = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    T.build(1, 1, n), m = read();
    for (int opt, x, y; m--;)
    {
        opt = read(), x = read(), y = read();
        if (opt == 1)
            T.modify(1, 1, n, x, y, read(), 0);
        if (opt == 2)
            T.modify(1, 1, n, x, y, read(), 1);
        if (opt == 3)
            printf("%lld\n", T.query(1, 1, n, x, y) % P);
    }
    return 0;
}