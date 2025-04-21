#include <bits/stdc++.h>
using i64 = long long;
#define int i64
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
	int T, s, t;
	cin >> T >> s >> t;
	if (T > 35 and s == 1 and t >= 33) {
		cout << "Bu Tie\n" << T;
		return;
	}
	if (T > 35 and t >= 33) {
		cout << "Shi Nei\n" << T;
		return;
	}
	if (s == 1) {
		cout << "Bu Re\n" << t;
		return;	
	}
	cout << "Shu Shi\n" << t;
	return;	
}

signed main() {
//	int T; cin >> T;
	int T = 1;
	while (T--) solve();
	return 0;
}