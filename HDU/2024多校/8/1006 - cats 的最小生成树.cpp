#include <bits/stdc++.h>
using i64 = long long;
#define pb push_back
using std::max, std::min;
using std::cin, std::cout, std::string, std::vector;
i64 read(i64 x = 0, i64 f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
struct DSU {
    std::vector<int> f, siz;
    DSU() {}
    DSU(int n) { init(n); }
    void init(int n) { f.resize(n), std::iota(f.begin(), f.end(), 0), siz.assign(n, 1); }
    int find(int x) { while (x != f[x]) x = f[x] = f[f[x]]; return x; }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        siz[x] += siz[y], f[y] = x;
        return true;
    }
    int size(int x) { return siz[find(x)]; }
};

void solve() {
    int n = read(), m = read();
    int k = m / (n - 1);

    vector<int> ans(m + 1, -1), cnt(k + 1);
    vector<DSU> dsu(k + 1, n + 1);

    for (int i = 1; i <= m; i++) {
    	int u = read(), v = read();
    	int res = 0;
    	for (int L = 1, R = k; L <= R; ) {
    		int mid = L + R >> 1;
    		if (cnt[mid] >= n - 1 or dsu[mid].same(u, v))
    			L = mid + 1;
    		else
    			res = mid, R = mid - 1;
    	}

    	if (res == 0) continue;

    	ans[i] = res, ++cnt[res];
    	dsu[res].merge(u, v);
    }

    for (int i = 1; i <= m; i++) {
    	if (cnt[ans[i]] != n - 1) ans[i] = -1;
    	cout << ans[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}