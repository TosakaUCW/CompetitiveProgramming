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
const int P = 998244353;

void solve() {
	int n = read();
	int k = read();
	string s;
	cin >> s;
	s = " " + s;
	vector<int> dp(n + 1), sum(n + 1);
	dp[1] = 1;
	
	
	vector<vector<int>> las(n + 1, vector<int>(26, 0));
	
	las[1][s[1] - 'a'] = 1;
	
	for (int i = 2; i <= n; i++) {
		dp[i] = 1;
		las[i] = las[i - 1];
		
		for (int j = 0; j < 26; j++) {
			if (i - k - 1 >= 1)
			dp[i] = (dp[i] + dp[las[i - k - 1][j]]) % P;	
		}
		
		las[i][s[i] - 'a'] = i;
	}
	
//	for (int i = 1; i <= n; i++) {
//		cout << dp[i] << " \n"[i == n];
//	}
	
	int ans = 0;
	for (int i = 0; i < 26; i++) ans = (ans + dp[las[n][i]]) % P;
	
	cout << ans << '\n';
}
/*
*/

signed main() {
	for (int T = read(); T--; solve());
//	solve();
	return 0;
}
