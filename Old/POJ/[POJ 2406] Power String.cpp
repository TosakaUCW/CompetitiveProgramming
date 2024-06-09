#include <stdio.h>
#include <string>
#include <iostream>

const int N = 1e6 + 5;

std::string S;
int nxt[N];

void get_next()
{
    nxt[0] = -1;
    for (int now = -1, i = 0; i < S.size(); )
        if (now == -1 or S[i] == S[now])
            nxt[++i] = ++now;
        else
            now = nxt[now];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    while (std::cin >> S and S[0] != '.')
    {
        get_next();
        int n = S.size(), m = n - nxt[n];
        printf("%d\n", n % m ? 1 : n / m);
    }
    return 0;
}