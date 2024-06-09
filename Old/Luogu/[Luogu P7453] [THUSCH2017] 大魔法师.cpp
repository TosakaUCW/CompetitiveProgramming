#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;
typedef unsigned char uc;
template<class _Tp>
using init_t = std::initializer_list<_Tp>;

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57)
		f = ch == '-', ch = getchar();
	while (48 <= ch and ch <= 57)
		x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 2.5e5 + 5;
const int mod = 998244353;
const ll MOD = 1LL * mod * mod;

int plus(int a, int b) { return (a += b) >= mod ? a -= mod : a; }
ll PLUS(ll a, ll b) { return (a += b) >= MOD ? a -= MOD : a; }

struct matrix {
  int c, r;
  // std::vector<std::vector<ll>> w;
  int w[4][4];
  explicit matrix(int _c = 0, int _r = 0) : c(_c), r(_r) { // c & r
    memset(w, 0, sizeof w);
    // w.resize(_c);
    // for (auto& column : w) column.resize(_r);
  }
  matrix(init_t<init_t<ll>> mat) { // initializer list
    memset(w, 0, sizeof w);
    c = mat.size(), r = 0;
    // w.resize(c);
    for (const auto& column : mat) r = std::max(r, static_cast<int>(column.size()));
    // for (int i = 0; i < mat.size(); i++) w[i].resize(r);
    int id_c = 0, id_r = 0;
    for (const auto& column : mat) {
      id_r = 0;
      for (auto element : column)
        w[id_c][id_r++] = element;
      id_c++;
    }
  }
  matrix(const matrix&) = default;
  matrix(matrix&&) = default;
  // matrix(matrix&& rhs) : c(rhs.c), r(rhs.r), w(std::move(rhs.w)) {};
  matrix& operator=(const matrix&) = default;
  matrix& operator=(matrix&&) = default;
  // matrix& operator=(matrix&& rhs) { r = rhs.r, c = rhs.c, w = std::move(rhs.w); return *this; }
  // std::vector<ll>& operator[] (int __n) { return w[__n]; }
  // const std::vector<ll>& operator[] (int __n) const { return w[__n]; }
  int* operator[] (uc __n) { return w[__n]; }
  const int* operator[] (uc __n) const { return w[__n]; }

  friend matrix operator*(const matrix& lhs, const matrix& rhs) {
    // if (lhs.r != rhs.c) {
    //  std::cerr << "invalid matrix * : lhs.r " << lhs.r << "!= rhs.c " << rhs.c << "." << std::endl;
    //  return matrix(0, 0);
    // }
    uc C = lhs.c, R = rhs.r, T = lhs.r;
    matrix res(C, R);
    ll sum[4];
    for (uc i = 0; i < C; i++) {
      for (uc j = 0; j < R; j++) sum[j] = 0;
      sum[0] = PLUS(sum[0], 1ll * lhs[i][0] * rhs[0][0]);
      sum[0] = PLUS(sum[0], 1ll * lhs[i][1] * rhs[1][0]);
      sum[0] = PLUS(sum[0], 1ll * lhs[i][2] * rhs[2][0]);
      sum[0] = PLUS(sum[0], 1ll * lhs[i][3] * rhs[3][0]);
      if (R == 4) {
        sum[1] = PLUS(sum[1], 1ll * lhs[i][0] * rhs[0][1]);
        sum[2] = PLUS(sum[2], 1ll * lhs[i][0] * rhs[0][2]);
        sum[3] = PLUS(sum[3], 1ll * lhs[i][0] * rhs[0][3]);
        sum[1] = PLUS(sum[1], 1ll * lhs[i][1] * rhs[1][1]);
        sum[2] = PLUS(sum[2], 1ll * lhs[i][1] * rhs[1][2]);
        sum[3] = PLUS(sum[3], 1ll * lhs[i][1] * rhs[1][3]);
        sum[1] = PLUS(sum[1], 1ll * lhs[i][2] * rhs[2][1]);
        sum[2] = PLUS(sum[2], 1ll * lhs[i][2] * rhs[2][2]);
        sum[3] = PLUS(sum[3], 1ll * lhs[i][2] * rhs[2][3]);
        sum[1] = PLUS(sum[1], 1ll * lhs[i][3] * rhs[3][1]);
        sum[2] = PLUS(sum[2], 1ll * lhs[i][3] * rhs[3][2]);
        sum[3] = PLUS(sum[3], 1ll * lhs[i][3] * rhs[3][3]);
      }
      for (uc j = 0; j < R; j++) res[i][j] = sum[j] % mod;
    }
    
    return res;
  }
  bool operator==(const matrix& rhs) { return w == rhs.w; }
  bool operator!=(const matrix& rhs) { return w != rhs.w; }
};

matrix I = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}},
       tr1 = {{1, 1, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}},
       tr2 = {{1, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}},
       tr3 = {{1, 0, 0, 0}, {0, 1, 0, 0}, {1, 0, 1, 0}, {0, 0, 0, 1}},
       tr4 = {{1, 0, 0, -1}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}},
       tr5 = {{1, 0, 0, 0}, {0, -1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}},
       tr6 = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, -1}, {0, 0, 0, 1}}, // left -1 for v
       base_sum = matrix(4, 1);

matrix& tr(int type) {
  switch(type) {
    case 1: return tr1;
    case 2: return tr2;
    case 3: return tr3;
    case 4: tr4[0][3] = read(); return tr4;
    case 5: tr5[1][1] = read(); return tr5;
    case 6: tr6[2][3] = read(); return tr6;
    // default:
      // std::cerr << "invalid transfrom : unknown type " << type << "." << std::endl;
  }
}

struct Node 
{ 
	ll p[3];
	void clear() { p[0] = p[1] = p[2] = 0;}
	Node friend operator + (Node x, Node y) 
	{
		Node z; z.clear();
		for (int i = 0; i < 3; i++) z.p[i] = plus(y.p[i], x.p[i]); 
		return z;
	}
};

int n;
matrix sum[N << 2], tag[N << 2];

struct Seg_Tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

	void pushup(int p) { for (int i = 0; i < 4; i++) sum[p][i][0] = plus(sum[ls][i][0], sum[rs][i][0]); }

	void update(int p, matrix k) { sum[p] = k * sum[p], tag[p] = k * tag[p]; }

	void pushdown(int p) { if (tag[p] != I) update(ls, tag[p]), update(rs, tag[p]), tag[p] = I; }

	void build(int p, int l, int r)
	{
		sum[p] = base_sum, tag[p] = I;
		sum[p][3][0] = r - l + 1;
		if (l == r)
		{
			for (int i = 0; i < 3; i++)	sum[p][i][0] = read();
			return;
		}
		build(ls, l, mid), build(rs, mid + 1, r), pushup(p);
	}

	void modify(int p, int l, int r, int x, int y, matrix k)
	{
		if (l == x and r == y) return update(p, k), void();
		pushdown(p);
		if (x <= mid) modify(ls, l, mid, x, std::min(mid, y), k);
		if (mid < y) modify(rs, mid + 1, r, std::max(mid + 1, x), y, k);
		pushup(p);
	}

	Node query(int p, int l, int r, int x, int y)
	{
		Node res; res.clear();
		if (l == x and r == y)
		{
			for (int i = 0; i < 3; i++) res.p[i] = sum[p][i][0];
			return res;
		}
		pushdown(p);
		if (x <= mid) res = res + query(ls, l, mid, x, std::min(mid, y));
		if (mid < y) res = res + query(rs, mid + 1, r, std::max(mid + 1, x), y);
		return res;
	}

#undef ls
#undef rs
#undef mid
} T;

int main()
{
	n = read();
	T.build(1, 1, n);
	for (int q = read(); q--; )
	{
		int opt = read(), l = read(), r = read();
		if (opt ^ 7) T.modify(1, 1, n, l, r, tr(opt));
		else
		{
			Node res = T.query(1, 1, n, l, r);
			for (int i = 0; i < 3; i++) printf("%lld ", res.p[i]);
			puts("");
		}
	}
	return 0;
}
