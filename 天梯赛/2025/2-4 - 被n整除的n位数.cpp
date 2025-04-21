#include <bits/stdc++.h>
using i64 = long long;
#define int i64
int read(int x = 0, int f = 0, char ch = getchar()) {
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second
// const int inf = 1e18;

void solve() {
	int n = read();
	int L = read();
	int R = read();

	int ten_n = 1;
	for (int i = 1; i < n; i++) {
		ten_n = ten_n * 10ll;
	}
	L = max(L, ten_n);
	R = min(R, ten_n * 10ll - 1);

	// cerr << ten_n << ' ' << L << ' ' << R << '\n';

	vector<int> ans;
	auto dfs = [&](auto &dfs, int cur, int ten, int len = 0) {
		if (cur % len != 0 or cur < L / ten or cur > R / ten) {
			return;
		}
		if (len == n) {
			ans.push_back(cur);
			return;
		}
		for (int i = 0; i < 10; i++) {
		  	dfs(dfs, cur * 10 + i, ten / 10, len + 1);
		}
	};
	for (int i = 0; i < 10; i++) {
		dfs(dfs, i, ten_n, 1);	
	}
	
	if (ans.empty()) {
		cout << "No Solution\n";
	} else {
		for (auto x : ans) {
			cout << x << '\n';
		}
	}
}
signed main() {
//	int T; cin >> T;
	int T = 1;
	while (T--) solve();
	return 0;
}