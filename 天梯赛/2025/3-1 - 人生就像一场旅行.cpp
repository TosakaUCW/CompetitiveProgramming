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
const int N = 5e2 + 5;

int dis[N][N];
int val[N][N];
int f[N][N], g[N][N];
struct Node {
	int x, dis, val;
};

void solve() {
	int b = read();
	int n = read();
	int m = read();
	int k = read();
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = inf; 
		}
		dis[i][i] = 0;
	}
	
	for (int i = 1; i <= m; i++) {
		int x = read();
		int y = read();
		dis[x][y] = dis[y][x] = read();
		val[x][y] = val[y][x] = read();
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dis[i][k] + dis[k][j] < dis[i][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
					val[i][j] = val[i][k] + val[k][j];
				} else if (dis[i][k] + dis[k][j] == dis[i][j]) {
					val[i][j] = max(val[i][j], val[i][k] + val[k][j]);
				}
				
			}
		}
	}
	
	while (k--) {
		int s = read();
		
		vector<int> ans;
		for (int t = 1; t <= n; t++) {
			if (s != t and dis[s][t] <= b) {
				ans.eb(t);
			}
		}
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i];
			if (i != ans.size() - 1) cout << ' ';
			else cout << '\n';
		}
		if (ans.size() == 0) {
			cout << "T_T\n";
			continue;	
		}
		
		int mx = 0;
		for (int i = 0; i < ans.size(); i++) {
			mx = max(mx, val[s][ans[i]]);
		}
		vector<int> res;
		for (int i = 0; i < ans.size(); i++) {
			if (val[s][ans[i]] != mx) continue;
			res.eb(ans[i]);
		}
		for (int i = 0; i < res.size(); i++) {
			cout << res[i];
			if (i != res.size() - 1) cout << ' ';
			else cout << '\n';
		}
	}
}
signed main() {
//	int T; cin >> T;
	int T = 1;
	while (T--) solve();
	return 0;
}