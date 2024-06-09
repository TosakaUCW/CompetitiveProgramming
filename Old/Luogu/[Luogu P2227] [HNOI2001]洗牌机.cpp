#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e3 + 5;

int n, s;

struct Node
{
    int a[N];
    void in() { for (int i = 1; i <= n; i++) a[i] = read(); }
    void out() { for (int i = 1; i <= n; i++) printf("%d ", a[i]); }
    void operator = (Node X) { for (int i = 1; i <= n; i++) a[i] = X.a[i]; }
    Node friend operator * (Node X, Node Y)
    {
        Node res;
        for (int i = 1; i <= n; i++) res.a[i] = Y.a[X.a[i]];
        return res;
    }
} A, I;

Node pow(Node A, int k)
{
    Node res = I;
    for (; k; k >>= 1, A = A * A) if (k & 1) res = res * A;
    return res;
}

int main()
{
    n = read(), s = read(), A.in();
    for (int i = 1; i <= n; i++) I.a[i] = i;
    while (s--) A = pow(A, (n + 1) >> 1);
    return A.out(), 0;
}
