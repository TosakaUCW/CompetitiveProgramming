#include <bits/stdc++.h>

void solve() {
    int n;
    std::string s; 
    std::cin >> n >> s;

    int t = s.size() - 1 - n;
    int c = s[n + t] - '0';

    std::vector<int> d(t);
    for (int i = 0; i < t; i++) {
        for (int j = 1; j <= n; j++) {
            if (j >> i & 1) {
                d[i] ^= (s[j - 1] - '0');
            }
        }
    }

    int sum = c;
    for (int i = 0; i < n; i++) sum ^= (s[i] - '0');

    if (sum == 1) {
        int f = 0;
        for (int i = 0; i < t; i++) {
            if (d[i] ^ (s[i + n] - '0') == 1) {
                f += (1 << i);
            }
        }
        if (f != 0) s[f - 1] = (s[f - 1] == '0') ? '1' : '0'; 
    }

    for (int i = 0; i < n; i++) putchar(s[i]);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    solve();
    return 0;
}