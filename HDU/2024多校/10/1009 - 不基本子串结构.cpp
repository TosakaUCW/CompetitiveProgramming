#include <bits/stdc++.h>
#define int long long
#define pb push_back
using std::max, std::min;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;
int nxt[N];

int go(string &A, string &B) {
    int n = A.size(), m = B.size();
    
    nxt[0] = -1;
    for (int now = -1, i = 0; i < m; )
        if (now == -1 or B[i] == B[now])
            nxt[++i] = ++now;
        else
            now = nxt[now];

    int cnt = 0, j = 0;
    for (int i = 0; i < n; ) {
        if (j == -1 or A[i] == B[j]) i++, j++;
        else j = nxt[j];
        if (j == m) {
            cnt++;
            j = nxt[j];
        }
    }
    
    if (cnt >= 2) return -1;
    if (cnt == 1) return n;
    return n + m - j;
}

void solve() {
    string A, B;
    cin >> A >> B;
    cout << min(go(A, B), go(B, A)) << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}