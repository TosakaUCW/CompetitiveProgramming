#include <bits/stdc++.h>
#define int long long
#define pb push_back
using std::cin, std::cout, std::string;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e3 + 5;
const int P = 95041567;
const int mod[] = {31, 37, 41, 43, 47};
const int M = 55;
// const long long INF = 1LL << 60;
int n, b[M][M];
struct Matrix
{
    int siz, P, a[M][M];
    Matrix friend operator * (Matrix a, Matrix b)
    {
        Matrix res;
        res.siz = a.siz, res.P = a.P;
        int P = a.P;
        for (int i = 1; i <= a.siz; i++)
            for (int j = 1; j <= a.siz; j++)
                for (int k = 1; k <= b.siz; k++)
                    res.a[i][j] = (res.a[i][j] + a.a[i][k] * b.a[k][j] % P) % P;
        return res;
    }
    Matrix pow(int k)
    {

    }
};
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif

    b[1][1] = 1;
    for (int i = 2; i <= 50; i++)
    {
        b[i][1] = b[i - 1][i - 1];
        for (int j = 2; j <= i; j++)
            b[i][j] = (b[i - 1][j - 1] + b[i][j - 1]) % P;
    }


    for (auto P : mod)
    {
        Matrix bas;
    }
    return 0;
}