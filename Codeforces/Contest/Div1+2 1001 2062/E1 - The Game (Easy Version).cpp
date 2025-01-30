#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }

void solve() {
    int n = read();
    vector<int> w(n);
    for (auto &x : w) x = read();

    vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; i++) {
		int u = read() - 1, v = read() - 1;
		g[u].eb(v), g[v].eb(u);
	}

	vector<int> p(n);
	ranges::iota(p, 0);
	ranges::sort(p, [&](int x, int y) {
		return w[x] > w[y];
	});

	vector<int> siz(n), dfn(n, -1), idx(n);
    int timer = 0;
    auto dfs = [&](this auto&& self, int u) -> void {
        siz[u] = 1;
        dfn[u] = timer++;
        idx[dfn[u]] = u;
        for (int v : g[u]) if (!siz[v]) {
            self(v);
            siz[u] += siz[v];
        }
    };
    dfs(0);

    vector<int> pre(n), suf(n);
    for (int i = 0; i < n; i++) pre[i] = suf[i] = w[idx[i]];
    for (int i = 1; i < n; i++) pre[i] = max(pre[i], pre[i - 1]);
    for (int i = n - 2; i >= 0; i--) suf[i] = max(suf[i], suf[i + 1]);

    for (int u : p) {
    	int res = 0;
    	if (dfn[u] - 1 >= 0) res = max(res, pre[dfn[u] - 1]);
    	if (dfn[u] + siz[u] < n) res = max(res, suf[dfn[u] + siz[u]]);

    	if (res > w[u]) {
    		cout << (u + 1) << '\n';
    		return;
    	}
    }

    cout << "0\n";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
