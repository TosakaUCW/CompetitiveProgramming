#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve()
{
    char s[10][12];
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 12; j++)
            cin >> s[i][j];
    bool f = 1;
    
    const string legal[] = {"132", "143", "236", "346", "125", "265", "645", "415"};
    auto check = [&](char a, char b, char c)
    {
        for (auto s : legal)
            for (int j = 0; j < 3; j++)
                if (a == s[j] and b == s[(j + 1) % 3] and c == s[(j + 2) % 3])
                    return;
        f = 0;
        std::array t {a, b, c};
        std::sort(t.begin(), t.end());
        for (auto ch : t) cout << ch << ' ';
        puts("");
    };
    
    check(s[3][4], s[4][4], s[4][3]); // 1 3 2
    check(s[3][6], s[4][7], s[4][6]); // 1 4 3
    check(s[6][3], s[6][4], s[7][4]); // 2 3 6
    check(s[6][6], s[6][7], s[7][6]); // 3 4 6
    
    check(s[1][4], s[4][1], s[4][12]); // 1 2 5
    check(s[6][1], s[9][4], s[6][12]); // 2 6 5
    check(s[9][6], s[6][9], s[6][10]); // 6 4 5
    check(s[4][9], s[1][6], s[4][10]); // 4 1 5
    
    if (f) puts("No problem");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}