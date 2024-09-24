#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap;
using std::cerr, std::cin, std::cout, std::string, std::vector;
int read(int x = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return x;
}

void solve() {
	int n = read();

	vector<int> rems;
	i64 ans = 0, sumb = 0;

	vector<int> a(n), b(n), c(n);

	for (int i = 0; i < n; i++) {
		c[i] = read(), a[i] = read(), b[i] = read();

		c[i] = (c[i] + ans) % n;

		if (c[i] == c[0]) {
			sumb += b[i];
			rems.eb(i);
		}

		vector<int> nrems;

		for (int j : rems) {
			if (c[i] == c[i - j]) {
				nrems.eb(j);
			} else {
				sumb -= b[j];
			}
		}

		ans += a[i] * sumb;
		cout << ans << "\n";
	}
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}