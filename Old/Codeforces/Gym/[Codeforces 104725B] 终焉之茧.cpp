#include <stdio.h>
#include <iostream>
#define int long long
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

int x, y;

int ask(int nx, int ny)
{
    std::cout << nx - x << ' ' << ny - y << std::endl;
    x = nx, y = ny;
    int ans = read();
    if (!ans) exit(0);
    return ans;
}

signed main()
{
    int d = read();
    if (!d) return 0;
    // x
    int L = -1000, R = 1000;
    int dL = ask(L, y), dR = ask(R, y);
    while (L + 2 <= R)
    {
        int mid = (L + R) >> 1;
        if (dL <= dR) R = mid, dR = ask(R, y);
        else L = mid, dL = ask(L, y);
    }
    if (dL < dR) ask(L, y);
    else ask(R, y);
    // y
    L = -1000, R = 1000;
    dL = ask(x, L), dR = ask(x, R);
    while (L + 2 <= R)
    {
        int mid = (L + R) >> 1;
        if (dL <= dR) R = mid, dR = ask(x, R);
        else L = mid, dL = ask(x, L);
    }
    if (!dL) ask(x, L);
    else ask(x, R);

    return 0;
}