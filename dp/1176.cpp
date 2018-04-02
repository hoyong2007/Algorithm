#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

using namespace std;

int N;
int cache[1000] = { 0 };

int search(int n)
{
	int tmp = 0;

	if (n <= 2)
		return n;

	if (!cache[n - 1])
		cache[n - 1] = search(n - 1)% 10007;
	tmp += cache[n - 1];

	if (!cache[n - 2])
		cache[n - 2] =  search(n - 2) % 10007;
	tmp += cache[n - 2];

	return tmp;
}

int main()
{
	scanf("%d", &N);

	printf("%d\n", search(N) % 10007);

	return 0;
}
