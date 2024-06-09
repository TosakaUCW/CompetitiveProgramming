#include <stdio.h>
#include <algorithm>
#include <iostream>
#define int long long
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int P = 998244353;
void solve()
{
    int x = read();
    for (; x <= 0; x += P);
    std::cout << x % P;
}
signed main()
{
    for (int T = 1; T--; solve());
    return 0;
}