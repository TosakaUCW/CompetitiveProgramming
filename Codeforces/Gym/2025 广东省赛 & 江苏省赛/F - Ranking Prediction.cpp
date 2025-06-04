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
struct node {
	int t;
	string p, v;
};

void solve() {
	int n = read();
	int a = read();
	int b = read();
	
	int s = read();
	vector<node> sub(s);
		
	int pass = 0;
	int tim = 0;
	map<string, int> ac;
	map<string, int> c;
	
	for (auto &[t, p, v] : sub) {
		cin >> t >> p >> v;
	}
	int ans = 0;
	
	vector<int> w;
	
	for (auto &[t, p, v] : sub) {
		if (ac[p]) continue;
		
		if (v == "pd") {
			ac[p] = 1;
			w.eb(t + c[p]);
		} else if (v == "ac") {
			tim += t + c[p];
			ac[p] = 1;
			pass++;
		} else {
			c[p] += 20;
		}	
	}
	
	if (pass > a or (pass == a and tim < b)) {
		cout << ans << "\n";
		return;
	}
	
	sort(w.begin(), w.end());
	for (auto x : w) {
		pass++;
		ans++;
		tim += x;
		
		if (pass > a or (pass == a and tim < b)) {
			cout << ans << "\n";
			return;
		}
	}
	
	cout << "-1\n";
}

signed main() {
	for (int T = read(); T--; solve());
//	solve();
	return 0;
}
