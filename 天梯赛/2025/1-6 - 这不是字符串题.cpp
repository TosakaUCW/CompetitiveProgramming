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
	int n = read();
	int m = read();
	vector<int> a(n);
	for (auto &x : a) x = read();
	
	while (m--) {
		int opt; cin >> opt;
		if (opt == 1) {
			int l1 = read();
			vector<int> s(l1);
			for (auto &x : s) x = read();
			int l2 = read();
			vector<int> t(l2);
			for (auto &x : t) x = read();
			
			int res = -1;
			for (int i = 0; i + l1 - 1 < n; i++) {
				int p = i, q = 0;
				while (a[p] == s[q] and q < l1 and p < n) p++, q++;
				if (q == l1) {
					res = i; 
					break;
				}
			}
			
			if (res != -1) {
				vector<int> b;
				for (int i = 0; i < res; i++) {
					b.eb(a[i]);
				}
				for (int i = 0; i < l2; i++) {
					b.eb(t[i]);
				}
				for (int i = res + l1; i < n; i++) {
					b.eb(a[i]);
				}
				n = b.size();
				a = move(b);
			}
		}
		if (opt == 2) {
			vector<int> b;
			for (int i = 0; i + 1 < n; i++) {
				b.eb(a[i]);
				int x = a[i] + a[i + 1];
				if (x % 2 == 0) b.eb(x / 2);
			}
			b.eb(a[n - 1]);
			n = b.size();
			a = move(b);
		}
		if (opt == 3) {
			int l = read() - 1;
			int r = read() - 1;
			l = max(l, 0ll);
			r = min(r, n - 1);
//			cout << "this" << l << '-' << r << '\n';
			while (l <= r) {
				swap(a[l], a[r]);
				l++, r--;
			}
		}
		
//		cout << "\n------------\n";
//		for (int i = 0; i < n; i++) {
//			cout << a[i] << ' ';
//		}
//		cout << '\n';
	}
	
//	cout << "------------\n";
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i != n - 1) cout << ' ';
	}
}
/*
14 9 2 21 8 21 9 10 21 5 4 5 14 1 26 8 5 14 4 5 2 21 19 8 9 26 9 6 21 3 8 21 1 14 20 9 2 1
14 9 2 21 8 21 9 10 21 5 4 5 14 1 26 8 5 14 4 5 2 21 19 8 9 26 9 6 21 3 8 21 1 14 20 9 2 1

14 9 2 21 8 21 9 10 21 5 4 5 14 1 26 8 5 14 4 5 2 21 19 8 9 26 9 6 21 3 8 21 1 14 20 9 1 2
14 9 2 21 8 21 9 10 21 5 4 5 14 1 26 8 5 14 4 5 2 21 19 8 9 26 9 6 21 3 8 21 1 14 20 9 1 2

14 9 2 21 8 21 9 10 21 5 4 5 14 1 26 8 5 14 4 5 2 21 19 8 9 1 2 3 4 5 6 7 8 9 10 11 12 13 14 1 2
14 9 2 21 8 21 9 10 21 5 4 5 14 1 26 8 5 14 4 5 2 21 19 8 9 1 2 3 4 5 6 7 8 9 10 11 12 13 14 1 2

14 9 2 21 8 21 15 9 10 21 13 5 4 5 14 1 26 17 8 5 14 9 4 5 2 21 20 19 8 9 5 1 2 3 4 5 6 7 8 9 10 11 12 13 14 1 2
14 9 2 21 8 21 15 9 10 21 13 5 4 5 14 1 26 17 8 5 14 9 4 5 2 21 20 19 8 9 5 1 2 3 4 5 6 7 8 9 10 11 12 13 14 1 2

14 9 8 7 6 5 4 3 2 1 5 9 8 19 20 21 2 5 4 9 14 5 8 17 26 1 14 5 4 5 13 21 10 9 15 21 8 21 2 9 10 11 12 13 14 1 2
*/
signed main() {
//	int T; cin >> T;
	int T = 1;
	while (T--) solve();
	return 0;
}