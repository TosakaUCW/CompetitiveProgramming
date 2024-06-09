#include <stdio.h>
#include <stdlib.h>

const int N = 1e5 + 5;
const int INF = 2147483647;

int root, cnt;
int L[N], R[N], key[N], val[N], size[N];

int New(int v)
{
	val[++cnt] = v;
	L[cnt] = R[cnt] = 0;
	key[cnt] = rand();
	size[cnt] = 1;
	return cnt;
}

void Updata(int p)
{
	size[p] = size[L[p]] + size[R[p]] + 1;
}

void Split(int p, int k, int &x, int &y)
{
	if (p == 0)
	{
		x = y = 0;
		return;
	}
	if (val[p] <= k)
		x = p, Split(R[p], k, R[x], y);
	else
		y = p, Split(L[p], k, x, L[y]);
	Updata(p);
}

void Merge(int &p, int x, int y)
{
	if (x == 0 or y == 0)
	{
		p = x | y;
		return;
	}
	if (key[x] >= key[y])
		p = x, Merge(R[x], R[p], y);
	else
		p = y, Merge(L[y], x, L[p]);
	Updata(p);
}

void Insert(int v)
{
	int x, y, z = New(v);
	Split(root, v, x, y);
	Merge(x, x, z);
	Merge(root, x, y);
}

void Delete(int v)
{
	int x, y, z;
	Split(root, v, x, y);
	Split(x, v - 1, x, z);
	Merge(z, L[z], R[z]);
	Merge(x, x, z);
	Merge(root, x, y);
}

int GetRankByVal(int v)
{
	int x, y, res;
	Split(root, v - 1, x, y);
	res = size[x];
	Merge(root, x, y);
	return res + 1;
}

int GetValByRank(int rank)
{
	int p = root;
	while (p)
	{
		if (size[L[p]] + 1 == rank)
			return val[p];
		else if (size[L[p]] >= rank)
			p = L[p];
		else
			rank -= 1 + size[L[p]], p = R[p];
	}
}

int GetPre(int v)
{
	int x, y, z;
	Split(root, v - 1, x, y);
	z = x;
	while (R[z])
		z = R[z];
	Merge(root, x, y);
	return val[z];
}

int GetNext(int v)
{
	int x, y, z;
	Split(root, v, x, y);
	z = y;
	while (L[z])
		z = L[z];
	Merge(root, x, y);
	return val[z];
}

int main()
{
	root = New(INF);
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int opt, x;
		scanf("%d%d", &opt, &x);
		switch (opt)
		{
		case 1:
			Insert(x);
			break;
		case 2:
			Delete(x);
			break;
		case 3:
			printf("%d\n", GetRankByVal(x));
			break;
		case 4:
			printf("%d\n", GetValByRank(x));
			break;
		case 5:
			printf("%d\n", GetPre(x));
			break;
		case 6:
			printf("%d\n", GetNext(x));
			break;
		}
	}
	return 0;
}