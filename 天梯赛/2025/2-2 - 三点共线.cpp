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

const int k = 1e6;
const int N = 2e6 + 5;

int vis[3][N];
int n;
vector<int> a[3];

signed main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;

		vis[y][x + k] = 1;
		a[y].eb(x);
	}

	for (int y = 0; y < 3; y++) {
    	sort(a[y].begin(), a[y].end());
    	a[y].resize(unique(a[y].begin(), a[y].end()) - a[y].begin());
  	}

	vector<int> p = {0, 1, 2};
	sort(p.begin(), p.end(), [&](int x, int y) {
		return a[x].size() < a[y].size();
	});

	using arr = array<int, 3>;
	vector<arr> ans;

	for (auto x1 : a[p[0]]) {
		for (auto x2 : a[p[1]]) {

			bool flag = 1;

			arr t = {-1, -1, -1};
			t[p[0]] = x1;
			t[p[1]] = x2;

			if (p[2] == 1) {
				if ((t[0] + t[2]) % 2 != 0) {
					flag = 0;
				}
				t[1] = (t[0] + t[2]) / 2;
			} else {
				t[p[2]] = t[1] * 2 - t[2 - p[2]];
			}

			for (int i = 0; i < 3; i++) {
				if (!vis[i][t[i] + k]) {
					flag = 0;
				}
			}

			if (flag) ans.pb(t);
		}
	}

	sort(ans.begin(), ans.end(), [&](auto x, auto y) {
		if (x[1] != y[1]) return x[1] < y[1];
		return x[0] < y[0];
	});

	if (ans.empty()) {
		cout << "-1\n";
	} else {
		for (auto [i, j, k] : ans) {
    		cout << "[" << i << ", 0] [" << j << ", 1] [" << k << ", 2]" << "\n";;
		}
	}
	return 0;
}