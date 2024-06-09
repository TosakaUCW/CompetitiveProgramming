#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

char S[N], P[N];
int nxt[N];

void get_next()
{
    nxt[0] = -1;
    int lenS = strlen(S);
    for (int now = -1, i = 0; i < lenS; )
        if (now == -1 or S[i] == S[now])
            nxt[++i] = ++now;
        else
            now = nxt[now];
}

void search()
{
    int res = 0, lenP = strlen(P), lenS = strlen(S);
    for (int i = 0, j = 0; i < lenP; )
    {
        if (j == -1 or P[i] == S[j]) i++, j++;
        else j = nxt[j];
        if (j == lenS)
        {
            res++;
            j = nxt[j];
        }
    }
    printf("%d\n", res);
}

void solve()
{
    // std::cin >> S >> P;
    scanf("%s%s", S, P);
    // memset(nxt, 0, sizeof nxt);
    get_next(), search();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}