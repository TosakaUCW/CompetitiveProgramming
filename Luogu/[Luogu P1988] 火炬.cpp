#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <queue>
#include <stdlib.h>

typedef unsigned long long llu;

llu read()
{
    llu x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

llu n;
std::queue<llu> Q;

bool judge(llu x)
{
    while (x)
    {
        if (x % 10 != 0 and x % 10 != 1)
            return false;
        x /= 10;
    }
    return true;
}

void bfs()
{
    Q.push(0);
    Q.push(1);
    while (!Q.empty())
    {
        llu x = Q.front();
        Q.pop();
        if (x % n == 0 and x >= n)
        {
            printf("%llu", x / n);
            exit(0);
        }
        Q.push(x * 10);
        Q.push(x * 10 + 1);
    }
}

void judge_9(llu x)
{
    llu cnt = 0, tmp = x / 9;
    while (tmp)
    {
        if (tmp % 10 != 1)
            return;
        tmp /= 10;
        cnt++;
    }
    for (int i = 1; i <= 7; i++)
        for (int j = 1; j <= cnt; j++)
            printf("%d", i);
    for (int j = 1; j < cnt; j++)
        printf("8");
    printf("9");
    exit(0);
}

int main()
{
    freopen("torch.in", "r", stdin);
    freopen("torch.out", "w", stdout);
    n = read();
    if (n % 9 == 0)
        judge_9(n);
    while (n % 10 == 0)
        n /= 10;
    // while(n)
    bfs();
    return 0;
}