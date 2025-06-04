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
const int N = 1e5 + 5;
const int M = 2e6 + 5;
const int P = 998244353;

void solve() {
	int n = read();
	int q = read();
	
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) a[i] = read();
	
	int m = a[n];
	
	vector<int> dp(m + 1), cnt(m + 1);
	for (int i = 1, j = 1; i <= m; i++) {
		while (j + 1 <= n and a[j + 1] <= i) j++;
		dp[i] = dp[i - a[j]] + 1;
		cnt[dp[i]]++;
	}
	vector<int> sum(m + 1);
	for (int i = 1; i <= m; i++) sum[i] = sum[i - 1] + cnt[i];
	
	for (int i = 1; i <= q; i++) {
		int x = read();
		if (x <= a[n]) {
			cout << sum[x] << " ";	
		} else {
			cout << sum[a[n]] << " ";
		}
	}
}

signed main() {
//	for (int T = read(); T--; solve());
	solve();
	return 0;
}