#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;

int n;

struct Node
{
    int val, pos;
    bool friend operator<(Node a, Node b) { return a.val < b.val; }
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
    for (int T = read(); T--;)
    {
        bool flag = true;
        n = read();
        for (int i = 1; i <= n; i++)
            a[i].val = read(), a[i].pos = i;
        std::stable_sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++)
            if (a[i].pos != i and a[i].val % a[1].val != 0)
            {
                flag = false;
                break;
            }
        if (flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}