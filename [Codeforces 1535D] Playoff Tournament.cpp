#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <string>

const int N = 3e5 + 5;

int n, k, q, f[N << 2];
std::string s;

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

void pushup(int p)
{
	if (s[p] == '?') f[p] = f[ls] + f[rs];
	else f[p] = s[p] - 48 ? f[ls] : f[rs];
}

void build(int p, int l, int r)
{
	if (l == r) return f[p] = 1, void();
	build(ls, l, mid), build(rs, mid + 1, r), pushup(p);
}

int main()
{
	std::cin >> k >> s;
	n = 1 << k, s.push_back('!'), std::reverse(s.begin(), s.end());
    build(1, 1, n);
	for (std::cin >> q; q--; )
	{
		char opt; int p;
		std::cin >> p >> opt;
        p = n - p, s[p] = opt;
		for (; p; p >>= 1) pushup(p);
		printf("%d\n", f[1]);
	}
	return 0;
}
