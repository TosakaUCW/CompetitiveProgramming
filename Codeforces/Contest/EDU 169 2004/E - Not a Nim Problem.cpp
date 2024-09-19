#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::max, std::min, std::swap;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

std::vector<int> minp, primes, sg;
void sieve(int n) {
    minp.assign(n + 1, 0), primes.clear();
    sg.assign(n + 1, 0);
    sg[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i, primes.push_back(i);
            sg[i] = primes.size();
        }
        sg[2] = 0;

        for (auto p : primes) {
            if (i * p > n) break;
            minp[i * p] = p;
            sg[i * p] = sg[p];
            if (p == minp[i]) break;
        }
    }
}

void solve() {
    int n = read();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans ^= sg[read()];
    }
    puts(ans ? "Alice" : "Bob");
}

signed main() {
    sieve(1e7);
    // for (int i = 1; i <= 20; i++) cout << sg[i] << '\n';
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}