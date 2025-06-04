#include <bits/stdc++.h>
using i64 = long long;
#define int i64
using namespace std;
#define eb emplace_back
#define pb 
int read(int x = 0, int f = 0, char ch = getchar()) {
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x; 
}

void solve() {
	int n = read();
	int k = 18;
	
	int v = 1, w = 1;
	vector<int> a, b;
	a.eb(v);
	b.eb(w);
	for (int i = 1; i <= 18; i++) {
		v *= 10ll;
		w *= 2ll;
		a.eb(v);
		b.eb(w);
	}
	
	int ans = 0;
	for (int i = 18; i >= 0; i--) {
		while (a[i] <= n) {
			ans += b[i];
			n -= a[i];
		}
	}
	
	cout << ans << '\n';
}

signed main() {
	for (int T = read(); T--; solve());
//	solve();
	return 0;
}
