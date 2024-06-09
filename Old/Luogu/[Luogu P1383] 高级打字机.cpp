#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>

const int N = 1e5 + 5;

int n, cnt = 1;

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

struct HJT_Tree
{
#define mid ((l + r) >> 1)
    int nodecnt, L[N << 5], R[N << 5], size[N << 5], rt[N];
    char val[N << 5];
    void modify(int &p, int pre, int l, int r, char ch)
    {
        p = (++nodecnt), L[p] = L[pre], R[p] = R[pre], size[p] = size[pre], val[p] = val[pre];
        if (l == r)
        {
            val[p] = ch;
            size[p] = 1;
            return;
        }
        if (size[L[p]] == mid - l + 1)
            modify(R[p], R[pre], mid + 1, r, ch);
        else
            modify(L[p], L[pre], l, mid, ch);
        size[p] = size[L[p]] + size[R[p]];
    }
    char query(int p, int l, int r, int x)
    {
        if (l == r)
            return val[p];
        if (size[L[p]] >= x)
            return query(L[p], l, mid, x);
        else
            return query(R[p], mid + 1, r, x - size[L[p]]);
    }
} T;

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        char opt, ch;
        scanf("%s", &opt);
        if (opt == 'T')
            scanf("%s", &ch), ++cnt, T.modify(T.rt[cnt], T.rt[cnt - 1], 1, n, ch);
        else if (opt == 'U')
            ++cnt, T.rt[cnt] = T.rt[cnt - 1 - read()];
        else
            printf("%c\n", T.query(T.rt[cnt], 1, n, read()));
    }
    return 0;
}