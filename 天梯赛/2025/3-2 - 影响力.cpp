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

const int N = 1e6 + 5;

int cnt = 0;
struct Node {
	int v, id, x, y;
} a[N];
int ans[N];
int pre[N];

void solve() {
	int n = read();
	int m = read();
	int k = n * m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			++cnt;
			auto &[v, id, x, y] = a[cnt];
			x = i + j;
			y = i - j;
			v = read();
			id = cnt;
		}
	}

	sort(a + 1, a + 1 + k, [&](auto i, auto j) {
		return i.x < j.x;
	});
	for (int i = 1; i <= k; i++) {
		pre[i] = pre[i - 1] + a[i].x;
	}
	for (int i = 1; i <= k; i++) {
		auto &[v, id, x, y] = a[i];
		ans[id] += x * (i - 1) - pre[i - 1];
		ans[id] += (pre[k] - pre[i]) - x * (k - i);
	}

	sort(a + 1, a + 1 + k, [&](auto i, auto j) {
		return i.y < j.y;
	});
	for (int i = 1; i <= k; i++) {
		pre[i] = pre[i - 1] + a[i].y;
	}
	for (int i = 1; i <= k; i++) {
		auto &[v, id, x, y] = a[i];
		ans[id] += y * (i - 1) - pre[i - 1];
		ans[id] += (pre[k] - pre[i]) - y * (k - i);
	}

	sort(a + 1, a + 1 + k, [&](auto i, auto j) {
		return i.id < j.id;
	});
	
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			++cnt;
			auto &[v, id, x, y] = a[cnt];
			int res = v * ans[id] / 2;
			cout << res;
			if (j != m) cout << ' ';
		}
		cout << '\n';
	}
}

signed main() {
	int T = 1;
	while (T--) solve();
	return 0;
}