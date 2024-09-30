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

void solve() {
    int n = read();
    
    vector<int> a(n), lst(n);
    for (int i = 0; i < n; i++) {
        a[i] = read() - 1;
        lst[a[i]] = i;
    }

    int top = -1;
    vector<int> stk(n), vis(n);

    for (int i = 0; i < n; i++) {
        if (vis[a[i]]) continue;

        while (top >= 0
            and (top & 1 ? a[stk[top]] > a[i] : a[stk[top]] < a[i])
            and lst[a[stk[top]]] > i) {
            vis[a[stk[top--]]] = 0;
        }

        while (top - 1 >= 0
            and (top - 1 & 1 ? a[stk[top - 1]] > a[i] : a[stk[top - 1]] < a[i])
            and lst[a[stk[top - 1]]] > i
            and lst[a[stk[top]]] > i) {
            vis[a[stk[top--]]] = 0;
            vis[a[stk[top--]]] = 0;
        }

        vis[a[stk[++top] = i]] = 1;
    }

    cout << top + 1 << '\n';
    for (int i = 0; i <= top; i++) {
        cout << a[stk[i]] + 1 << " \n"[i == top];
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}