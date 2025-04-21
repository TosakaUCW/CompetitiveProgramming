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
const int inf = 1e18;
const int N = 1e3 + 5;

int a[N][N];
bool visx[N], visy[N];
struct Node {
	int v, x, y;
	bool friend operator < (Node a, Node b) {
		return a.v > b.v;
	}
};

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<Node> b;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			b.push_back({a[i][j], i, j});
		}
	}
	
	sort(b.begin(), b.end());
	int cnt = 0;
	for (auto t : b) {
		if (cnt == k) break;
		int x = t.x;
		int y = t.y;
		
		if (visx[x] or visy[y]) continue;
		visx[x] = visy[y] = 1;
		cnt++;
	}

	for (int i = 1; i <= n; i++) {
		if (visx[i]) continue;
		
		vector<int> t;
		for (int j = 1; j <= m; j++) {
			if (visy[j]) continue;
			t.push_back(a[i][j]);
		}
		
		int s = t.size();
		for (int i = 0; i < s; i++) {
			cout << t[i];
			if (i == s - 1) cout << "\n";
			else cout << " ";
		}
	}
}

signed main() {
//	int T; cin >> T;
	int T = 1;
	while (T--) solve();
	return 0;
}