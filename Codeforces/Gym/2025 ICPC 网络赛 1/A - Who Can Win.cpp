#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;
struct Node {
    int id, prob, tim, sta;
};

void solve() {
    int n = read();

    vector<Node> a(n);

    unordered_map<string, int> buk; buk.reserve(n);
    unordered_map<int, string> Name; Name.reserve(n);
    set<string> winner;

    int cnt = 0;
    for (auto &[id, prob, tim, sta] : a) {
        string s; cin >> s;
        if (!buk.count(s)) buk[s] = cnt++, Name[cnt - 1] = s;
        id = buk[s];

        cin >> s; prob = s[0] - 'A';
        cin >> tim;
        cin >> s; sta = s == "Accepted" ? 1 : 0;
    }

    ranges::sort(a, [&](auto i, auto j) {
        return i.tim < j.tim;
    });

    vector penalty(cnt, 0);
    vector ac(cnt, 0);
    vector pntime(cnt, vector(26, 0));
    
    for (auto &[id, prob, tim, sta] : a) if (tim < 240) {
        if (pntime[id][prob] == -1) continue;

        if (sta == 1) {
            penalty[id] += tim + pntime[id][prob];
            ac[id]++;
            pntime[id][prob] = -1;
        } else {
            pntime[id][prob] += 20;
        }
    }

    vector<int> p(cnt);
    ranges::iota(p, 0);
    ranges::sort(p, [&](int i, int j) {
        if (ac[i] != ac[j]) return ac[i] > ac[j];
        return penalty[i] < penalty[j];
    });

    int best_pnt = penalty[p[0]];
    int best_ac = ac[p[0]];
    winner.insert(Name[p[0]]);

    for (int i = 1; i < cnt; i++) {
        int id = p[i];
        if ((ac[id] > best_ac) or (ac[id] == best_ac and penalty[id] <= best_pnt)) {
            winner.insert(Name[id]);
        }
    }

    for (auto &[id, prob, tim, sta] : a) if (tim >= 240) {
        if (pntime[id][prob] == -1) continue;

        penalty[id] += tim + pntime[id][prob];
        ac[id]++;
        pntime[id][prob] = -1;

        if ((ac[id] > best_ac) or (ac[id] == best_ac and penalty[id] <= best_pnt)) {
            winner.insert(Name[id]);
        }
    }


    for (auto x : winner) {
        cout << x << " ";
    }
    cout << "\n";
}


signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}