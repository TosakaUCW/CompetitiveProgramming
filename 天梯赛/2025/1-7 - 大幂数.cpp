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

void solve() {
	int n; cin >> n;
	int ans1 = 0, ans2 = 0;
	for (int k = 1; k <= 30; k++) {
		int res = 0;
		int now = n;
		bool flag = 1;
		int mx = -1;
		for (int i = 1; i <= 100000 and now > 0; i++) {
			int x = 1;
			for (int t = 1; t <= k; t++) {
				x *= i;
				if (now < x) {
					now = -1;
					break;
				}
			}
			now -= x;
			
			if (now == 0) {
				mx = i;
				break;
			}
		}
		
		if (now == 0) {
			ans1 = mx, ans2 = k;
		}
	}
	if (ans2 == 0) {
		cout << "Impossible for " << n << ".\n";
		return;
	}
	for (int i = 1; i <= ans1; i++) {
		cout << i << "^" << ans2;
		if (i != ans1) cout << "+";
	}
} 
signed main() {
//	int T; cin >> T;
	int T = 1;
	while (T--) solve();
	return 0;
}