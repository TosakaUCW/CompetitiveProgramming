#include <bits/stdc++.h>
using i64 = long long;
#define int i64
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

void solve() {
    int l = read();
    int r = read();

    auto calc = [&](int x, int y, int z) {
        return (x ^ y) + (y ^ z) + (x ^ z);
    };

    int sum = 0; 
    int p = 30; 
    #define x (1LL << p)
    while (p >= 0) { 
        if ((l & x) == (r & x)) { 
            if (l & x) sum += x; 
        } else break; 
        --p; 
    } 
    if (r > sum + x) { 
        cout << sum + x - 1 << ' ' 
             << sum + x << ' ' 
             << sum + x + 1 << '\n'; 
    } else { 
        cout << sum + x - 2 << ' ' 
             << sum + x - 1 << ' ' 
             << sum + x << '\n'; 
    } 
}

/*
(a+b+c) ^ a ^ b ^ c

111
110
100

1
101

000

----
01111
00110
01001

11110
-----
1000 0100
1000 0110
1000 1001

11110
-----
137 = 1000 1001

1000 1001
1000 1001
1000 1000


1000 0011=131
1000 0101=133
1000 0110=134
*/

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
