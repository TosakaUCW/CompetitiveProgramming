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
const int P = 998244353;
int a[N], b[N];

void solve() {
	int n = read();
	int q = read();
	
//	vector<int
	
	for (int i = 1; i <= n; i++) a[i] = read();
	
	for (int i = 1; i <= q; i++) {
//		int x = read();
		int x = i;
		int ans = 0;
		for (int j = 1; j <= 1000000; j++) {
			int r = j;
			int res = 0;
			for (int i = n; i >= 1; i--) {
				res += r / a[i];
				r %= a[i];
			}
			if (res == x) {
//				cout << j << ' ';
				ans++;
			}
		}
		
		cout <<ans <<'\n';
	}
}
/*
6 10
1 5 10 20 50 100
1 2
*/

signed main() {
//	for (int T = read(); T--; solve());
	solve();
	return 0;
}
