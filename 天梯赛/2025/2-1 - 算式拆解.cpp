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

void solve() {
	string s;
	cin >> s;
	
	int n = s.size();
	vector<int> vis(n);
	vector<int> stk;

	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			stk.eb(i);
		} else if (s[i] == ')') {
			int l = stk.back();
			stk.pop_back();

			vis[l] = vis[i] = 1;

			for (int j = l + 1; j < i; j++) {
				if (!vis[j]) cout << s[j];
				vis[j] = 1;
			}
			cout << "\n";
		}
	}

}
signed main() {
//	int T; cin >> T;
	int T = 1;
	while (T--) solve();
	return 0;
}