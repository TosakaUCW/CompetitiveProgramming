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

struct Node {
    int val, pos;
    bool friend operator < (Node a, Node b) {
        if (a.val - a.pos != b.val - b.pos) return a.val - a.pos < b.val - b.pos;
        return a.val < b.val;
    }
};
struct node {
    int val, pos;
    bool friend operator < (node a, node b) {
        if (a.val - a.pos != b.val - b.pos) return a.val - a.pos < b.val - b.pos;
        return a.val < b.val;
    }
};

void solve() {

    // int n = read();
    
    string s;
    cin >> s;

    int n = s.size();

    std::priority_queue<Node> q;

    // std::priority_queue<node> q0;

    for (int i = 0; i < n; i++) {
        q.ep(s[i] - '0', i);
    }

    // cerr << q.top().val << '\n';

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }

    // cout << a << '\n';

    for (int i = 0; i < n; i++) {
        int x = a[i];
        int pos = i;
        for (int j = i - 1; j >= 0; j--) {
            if (a[i] - (i - j) < 0) break;
            if (a[i] - (i - j) > a[j]) {
                pos = j;
            }
        }

        if (pos != i) {
            int now = a[i] - (i - pos);
            // a[i] -= (i - pos);
            // swap(a[i], a[pos])
            for (int j = i - 1; j >= pos; j--) {
                swap(a[j], a[j + 1]);
            }
            a[pos] = now;
        }

        // cout << a << '\n';
        
    }

    for (auto x : a) {
        cout << x;
    }
    puts("");
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}