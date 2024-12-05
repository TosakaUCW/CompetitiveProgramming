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
// using namespace std;
using std::ostream;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

const int inf = 1e18;

void solve() {

    int n = read();
    
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
    }

    if (sum % n != 0) {
        puts("NO");
        return;
    }

    sum /= n;

    for (int i = 1; i + 2 <= n; i++) {
        if (a[i] == sum) continue;
        if (a[i] < sum) {
            a[i + 2] -= (sum - a[i]);
            a[i] = sum;
        } else {
            a[i + 2] += (a[i] - sum);
            // a[i] -= a[i] - sum;
            a[i] = sum;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] != sum) {
            puts("NO");
            return;
        }
    }

    puts("YES");

}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}