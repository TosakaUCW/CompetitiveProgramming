#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
// using namespace std::views;
// using namespace std::ranges;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
using std::ostream;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<double, double>;
#define fi first
#define se second

const double eps = 1e-10;
const double pi = acos(-1.0);

int sgn(double x) {
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

void solve() {
    int n = read();
    int m = read();

    vector<int> a(n), b(m);
    for (auto &x : a) x = read();
    for (auto &x : b) x = read();

    int atk = 0;
    int boom = 0;
    bool first1 = 1;

    for (int &x : a) {
        if (x != 1) {
            x--;
            atk++;
        } else {
            if (!first1) continue;

            first1 = 0;
            x--;
            atk++;
            // boom++;
        }
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    for (int i = 0, j = 0; j < m; ) {
        while (i < n and a[i] <= boom) {
            i++;
            boom++;
        }
        
        if (b[j] > boom + atk) {
            puts("No");
            return;
        }

        atk -= max(0, b[j] - boom);
        boom++;
        j++;
    }
    puts("Yes");
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
