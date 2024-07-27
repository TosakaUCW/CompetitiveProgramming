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

const int N = 1e5 + 5;
const int M = N << 2;
int n, a[N], d[N];

struct SGT
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid (l + r >> 1)
    int pos[M], mx[M], tag[M];
    void push_down(int p)
    {
        if (tag[p])
        {
            mx[ls] += tag[p], mx[rs] += tag[p];
            tag[ls] += tag[p], tag[rs] += tag[p];
            tag[p] = 0;
        }
    }
    void pushup(int p)
    {
        if (mx[ls] > mx[rs]) mx[p] = mx[ls], pos[p] = pos[ls];
        else mx[p] = mx[rs], pos[p] = pos[rs];
    }
    void build(int p, int l, int r)
    {
        if (l == r) return mx[p] = a[l], pos[p] = l, void();
        build(ls, l, mid), build(rs, mid + 1, r);
        pushup(p);
    }
    void add(int p, int l, int r, int ql, int qr, int k)
    {
        if (ql <= l and r <= qr)
        {
            mx[p] += k, tag[p] += k;
            return;
        }
        push_down(p);
        if (ql <= mid) add(ls, l, mid, ql, qr, k);
        if (mid < qr) add(rs, mid + 1, r, ql, qr, k);
        pushup(p);
    }
    int queryMax(int p, int l, int r, int ql, int qr)
    {
        if (ql <= l and r <= qr) return pos[p];
        push_down(p);
        int res = 0;
        if (ql <= mid)
        {
            int t = queryMax(ls, l, mid, ql, qr);
            if (a[t] > a[res]) res = t;
        }
        if (mid < qr)
        {
            int t = queryMax(rs, mid + 1, r, ql, qr);
            if (a[t] > a[res]) res = t;
        }
        return res;
    }
} T;

int f1(int x) { return x > 0; }
int f2(int x) { return x < 0; }
int f3(int x) { return x == 0; }

struct BIT {
	int c[N];
	int lowbit(int x) { return x & (-x); }
	void add(int x, int v) { for(; x <= n; x += lowbit(x)) c[x]+=v; }
	int qry(int x) {
		int res = 0; 
		for(; x; x -= lowbit(x))
			res += c[x];
		return res;
	}
} bit1, bit2, bit3;

void modify(int l, int r, int v) {
	bit1.add(l, f1(d[l] + v) - f1(d[l]));
	bit1.add(r + 1, f1(d[r + 1] - v) - f1(d[r + 1]));
    
    bit2.add(l, f2(d[l] + v) - f2(d[l]));
	bit2.add(r + 1, f2(d[r + 1] - v) - f2(d[r + 1]));
    
    bit3.add(l, f3(d[l] + v) - f3(d[l]));
	bit3.add(r + 1, f3(d[r + 1] - v) - f3(d[r + 1]));

	d[l] += v, d[r + 1] -= v;
}

bool check1(int l, int r) { return bit1.qry(r) - bit1.qry(l) == r - l; }
bool check2(int l, int r) { return bit2.qry(r) - bit2.qry(l) == r - l; }
bool check3(int l, int r) { return bit3.qry(r) - bit3.qry(l) == r - l; }

signed main() {    
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif

    n = read();

    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) d[i] = a[i] - a[i - 1];
    
    T.build(1, 1, n);
    for (int i = 1; i <= n; i++) bit1.add(i, f1(d[i]));
    for (int i = 1; i <= n; i++) bit2.add(i, f2(d[i]));
    for (int i = 1; i <= n; i++) bit3.add(i, f3(d[i]));
    
    for(int q = read(), opt, l, r; q--; ) 
    {
        opt = read(), l = read(), r = read();
        if (opt == 1) 
        {
            int t = read();
            modify(l, r, t);
            T.add(1, 1, n, l, r, t);
        }
        if (opt == 2) puts(check3(l, r) ? "1" : "0");
        if (opt == 3) puts(check1(l, r) ? "1" : "0");
        if (opt == 4) puts(check2(l, r) ? "1" : "0");
        if (opt == 5)
        {
            int t = T.queryMax(1, 1, n, l + 1, r - 1);
            puts(check1(l, t) and check2(t, r) ? "1" : "0");
        }
	}
    return 0;
}