#include <stdio.h>
#include <algorithm>
#include <stack>

const int N = 2e5 + 5;

int n, top;
int ans[N];
std::stack<int> S;

struct Node
{
    int opt, val;
} a[N];

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

int main()
{
    n = read();
    for (int i = 1; i <= n << 1; i++)
    {
        char opt;
        scanf("%s", &opt);
        if (opt == '+')
            a[i].opt = 1;
        else
            a[i].val = read(), a[i].opt = 2;
    }
    n <<= 1;
    for (int i = 1; i <= n; i++)
        if (a[i].opt == 1)
            top++;
        else if (!top)
            return puts("NO"), 0;
        else
            top--;
    int now = n >> 1;
    for (int i = n; i; i--)
        if (a[i].opt == 1)
            ans[now--] = S.top(), S.pop();
        else if (!S.empty() and a[i].val > S.top())
            return puts("NO"), 0;
        else
            S.push(a[i].val);
    puts("YES");
    for (int i = 1; i <= n >> 1; i++)
        printf("%d ", ans[i]);
    return 0;
}