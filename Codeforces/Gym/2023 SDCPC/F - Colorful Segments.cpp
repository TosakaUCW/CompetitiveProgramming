#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap;
using std::cin, std::cout, std::string, std::vector;
i64 read(i64 x = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return x;
}
template <class T>
constexpr T power(T a, i64 b) { T res {1}; for (; b; b /= 2, a *= a) if (b % 2) res *= a; return res; }
constexpr i64 mul(i64 a, i64 b, i64 p) { i64 res = a * b - (i64)(1.L * a * b / p) * p; res %= p; if (res < 0) res += p; return res; }
template <i64 P>
struct MInt {
    i64 x;
    constexpr MInt() : x {0} {}
    constexpr MInt(i64 x) : x {norm(x % getMod())} {}
    static i64 Mod;
    constexpr static i64 getMod() { return P > 0 ? P : Mod; }
    constexpr static void setMod(i64 Mod_) { Mod = Mod_; }
    constexpr i64 norm(i64 x) const { if (x < 0) x += getMod(); if (x >= getMod()) x -= getMod(); return x; }
    constexpr i64 val() const { return x; }
    constexpr MInt operator-() const { MInt res; res.x = norm(getMod() - x); return res; }
    constexpr MInt inv() const { return power(*this, getMod() - 2); }
    constexpr MInt &operator*=(MInt rhs) & { if (getMod() < (1ULL << 31)) x = x * rhs.x % int(getMod()); else x = mul(x, rhs.x, getMod()); return *this; }
    constexpr MInt &operator+=(MInt rhs) & { x = norm(x + rhs.x); return *this; }
    constexpr MInt &operator-=(MInt rhs) & { x = norm(x - rhs.x); return *this; }
    constexpr MInt &operator/=(MInt rhs) & { return *this *= rhs.inv(); }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) { MInt res = lhs; res *= rhs; return res; }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) { MInt res = lhs; res += rhs; return res; }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) { MInt res = lhs; res -= rhs; return res; }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) { MInt res = lhs; res /= rhs; return res; }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) { i64 v; is >> v; a = MInt(v); return is; }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) { return os << a.val(); }
    friend constexpr bool operator==(MInt lhs, MInt rhs) { return lhs.val() == rhs.val(); }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) { return lhs.val() != rhs.val(); }
    friend constexpr bool operator<(MInt lhs, MInt rhs) { return lhs.val() < rhs.val(); }
};
template <>
i64 MInt<0>::Mod = 998244353;
constexpr int P = 998244353;
using Z = MInt<P>;

struct SGT {
	#define mid (l + r >> 1)
	#define ls (p << 1)
	#define rs (p << 1 | 1)
	vector<Z> sum, laz;

	SGT() {}
    SGT(int n) { init(n); }

    void init(int n) { 
    	int siz = 4 * n + 5;
    	sum.resize(siz), laz.resize(siz);
    	sum.assign(siz, 0), laz.assign(siz, 1);
    }

    void down(int p) {
    	auto &t = laz[p];
    	if (t == 1) return;

    	sum[ls] *= t;
    	sum[rs] *= t;
    	laz[ls] *= t;
    	laz[rs] *= t;
    	t = 1;
    }
    void up(int p) {
    	sum[p] = sum[ls] + sum[rs];
    }

    void add(int p, int l, int r, int pos, Z val) {
    	if (l == r) {
    		sum[p] += val;
    	} else {
    		down(p);
	    	if (pos <= mid) add(ls, l, mid, pos, val);
	    	else add(rs, mid + 1, r, pos, val);
	    	up(p);	
    	}
    }

    void mul2(int p, int l, int r, int pos) {
    	if (r <= pos) {
    		sum[p] *= 2;
    		laz[p] *= 2;
    	} else {
    		down(p);
    		mul2(ls, l, mid, pos);
    		if (mid < pos) mul2(rs, mid + 1, r, pos);
    		up(p);
    	}
    }

    Z query(int p, int l, int r, int pos) {
    	if (r <= pos) {
    		return sum[p];
    	} else {
    		down(p);
    		Z res = query(ls, l, mid, pos);
    		if (mid < pos) res += query(rs, mid + 1, r, pos);
    		up(p);
    		return res;
    	}
    }

};

void solve() {
	int n = read();

	vector<std::array<int, 3>> a(n + 1);
	for (int i = 1; i <= n; i++) {
		for (auto &x : a[i]) {
			x = read();
		}
	}

	std::sort(a.begin() + 1, a.end(), [](auto a, auto b){
		return a[1] < b[1];
	});

	SGT t[2] {SGT(n), SGT(n)};

	for (int k = 0; k < 2; k++) {
		t[k].add(1, 0, n, 0, 1);
	}

	Z ans = 1;
	for (int i = 1; i <= n; i++) {
		int p = 0;
		int &c = a[i][2];
		for (int l = 0, r = i - 1; l <= r; ) {
			if (a[mid][1] < a[i][0]) p = mid, l = mid + 1;
			else r = mid - 1;
		}

		Z val = t[c ^ 1].query(1, 0, n, p);
		t[c].add(1, 0, n, i, val);
		t[c ^ 1].mul2(1, 0, n, p);
		ans += val;
	}
	cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    return 0;
}