#include <stdio.h>
#include <algorithm>

typedef long long ll;

const int G = 3;
const int N = 3e5 + 5;
const int P = 998244353;

int n, m, limit = 1;
int L, R[N];
int fac[N], inv[N], pow2[N];
int A[N], B[N];

int pow(int x, int k)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res = (ll)res * x % P;
        x = (ll)x * x % P;
        k >>= 1;
    }
    return res;
}

void prepare()
{
    fac[0] = inv[0] = pow2[0] = A[0] = B[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = (ll)fac[i - 1] * i % P;
        inv[i] = pow(fac[i], P - 2);
        pow2[i] = pow2[i - 1] << 1;
        if (pow2[i] >= P)
            pow2[i] -= P;
        A[i] = inv[i];
        if (i & 1)
            A[i] = P - A[i];
        B[i] = (ll)(pow(i, n + 1) - 1) % P * inv[i] % P * pow(i - 1, P - 2) % P;
    }
    B[1] = n + 1;
    while (limit <= n * 2)
        limit <<= 1, L++;
    R[0] = 0;
    for (int i = 1; i < limit; i++)
        R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
}

void Fast_Fourier_Transform(int *A, int type)
{
    for (int i = 0; i < limit; i++)
        if (i < R[i])
            std::swap(A[i], A[R[i]]);
    for (int i = 1; i < limit; i <<= 1)
    {
        int Gn = pow(G, (P - 1) / (i << 1));
        if (type == -1)
            Gn = pow(Gn, P - 2);
        for (int j = 0, p = i << 1; j < limit; j += p)
        {
            int Gi = 1;
            for (int k = 0; k < i; k++, Gi = (ll)Gi * Gn % P)
            {
                int x = A[j + k], y = (ll)Gi * A[i + j + k] % P;
                A[j + k] = x + y, A[i + j + k] = x - y + P;
                if (A[j + k] >= P)
                    A[j + k] -= P;
                if (A[j + i + k] >= P)
                    A[j + i + k] -= P;
            }
        }
    }
    if (type == -1)
    {
        int inv = pow(limit, P - 2);
        for (int i = 0; i < limit; i++)
            A[i] = (ll)A[i] * inv % P;
    }
}

int main()
{
    scanf("%d", &n);
    prepare();
    Fast_Fourier_Transform(A, 1);
    Fast_Fourier_Transform(B, 1);
    for (int i = 0; i < limit; i++)
        A[i] = (ll)A[i] * B[i] % P;
    Fast_Fourier_Transform(A, -1);
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans += (ll)pow2[i] * fac[i] % P * A[i] % P;
        if (ans >= P)
            ans -= P;
    }
    printf("%d", ans);
    return 0;
}