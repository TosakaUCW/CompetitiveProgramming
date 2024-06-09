#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <complex>

typedef std::complex<double> E;

const int N = 2e5 + 5;
const double Pi = acos(-1);

int n, m, limit = 1;
int L, R[N], ANS[N];
char s1[N], s2[N];
E A[N], B[N];

void Fast_Fourier_Transform(E *A, int type)
{
    for (int i = 0; i < limit; i++)
        if (i < R[i])
            std::swap(A[i], A[R[i]]);
    for (int i = 1; i < limit; i <<= 1)
    {
        E Wn(cos(Pi / i), type * sin(Pi / i));
        for (int j = 0, p = i << 1; j < limit; j += p)
        {
            E w(1, 0);
            for (int k = 0; k < i; k++, w *= Wn)
            {
                E x = A[j + k], y = w * A[i + j + k];
                A[j + k] = x + y, A[i + j + k] = x - y;
            }
        }
    }
}

int main()
{

    scanf("%d%s%s", &n, &s1, &s2);
    m = n;
    for (int i = n - 1, j = 0; i >= 0; i--, j++)
        A[j] = s1[i] - '0', B[j] = s2[i] - '0';
    while (limit <= n + m)
        limit <<= 1, L++;
    for (int i = 0; i < limit; i++)
        R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
    Fast_Fourier_Transform(A, 1);
    Fast_Fourier_Transform(B, 1);
    for (int i = 0; i <= limit; i++)
        A[i] *= B[i];
    Fast_Fourier_Transform(A, -1);
    for (int i = 0; i <= limit; i++)
    {
        ANS[i] += (int)(A[i].real() / limit + 0.5);
        if (ANS[i] >= 10)
            ANS[i + 1] += ANS[i] / 10, ANS[i] %= 10, limit += (i == limit);
    }
    while (!ANS[limit] and limit >= 1)
        limit--;
    limit++;
    while (--limit >= 0)
        printf("%d", ANS[limit]);
    return 0;
}