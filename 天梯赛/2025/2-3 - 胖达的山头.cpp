#include <bits/stdc++.h>
// using i64 = long long;
// #define int i64
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

const int N = 1e5 + 5;
int a[N], b[N];
int d[N], s[N];

void solve() {
	int n = read();
	map<int, int> buk;
	for (int i = 1; i <= n; i++) {
		string s, t;
		cin >> s >> t;
		for (auto ch : s) {
			if (ch == ':') continue;
			a[i] = a[i] * 10 + ch - 48;
		}
		for (auto ch : t) {
			if (ch == ':') continue;
			b[i] = b[i] * 10 + ch - 48;
		}
//		cout << a[i] << ' ' << b[i] << '\n';
		buk[a[i]] = 1;
		buk[b[i]] = 1;
	}
	
	int t = 0;
	for (auto &[x, y] : buk) {
		y = ++t;
	}
	for (int i = 1; i <= n; i++) {
		a[i] = buk[a[i]];
		b[i] = buk[b[i]];
		d[a[i]]++;
		d[b[i] + 1]--;
//		cout << a[i] << ' ' << b[i] << '\n';
	}
	
	int ans = 0;
	for (int i = 1; i <= t; i++) {
		s[i] = s[i - 1] + d[i];
//		cout << s[i] << ' ';
		ans = max(ans, s[i]);
	}
	cout << ans << '\n';
}

signed main() {
//	int T; cin >> T;
	int T = 1;
	while (T--) solve();
	return 0;
}