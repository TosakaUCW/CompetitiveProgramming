#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read();
    int p = read(), q = read();

    using pii = std::pair<int, int>;
    #define fi first 
    #define se second

    vector<pii> a(n);
    for (auto &[x, y] : a) {
        x = read(), y = read();
    }

    std::sort(a.begin(), a.end(), [](pii x, pii y) {
        return x.fi == y.fi ? x.se > y.se: x.fi < y.fi;
    });

    std::set<int> s;
    int ans = p * (p + 1) / 2 * (q + 1)
            + q * (q + 1) / 2 * (p + 1);

    int sum = 0, las = 0;
    for (auto [x, y] : a) {
        if (x >= p) break;
        if (y >= q) continue;

        if (las <= x) {
            ans -= (x - las + 1) * sum;
            las = x + 1;
        }

        if (s.empty() or y > *std::prev(s.end())) {
            s.insert(y);
            sum += q - y;
        } else {
            auto it = s.lower_bound(y);

            sum -= q - *it;
            sum += q - y;
            s.erase(it);
            s.insert(y);
        }
    }

    if (las <= p) {
        ans -= (p - las + 1) * sum;
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    return 0;
}