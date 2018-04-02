#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>
#include <utility>
#pragma warning(disable:4996)

using namespace std;

int N, MAX;
int triangle[510][510] = { 0 };


int cache[510][510] = { 0 };

void search(int n) 
{
	for (int j = 0; j < N; j++) {
		if (!cache[n - 1][0] && n-1>=0)
			search(n - 1);
		if (j == 0)
			cache[n][0] = cache[n - 1][0] + triangle[n][0];
		else if (j == n)
			cache[n][n] = cache[n - 1][n - 1] + triangle[n][n];
		else
			cache[n][j] = (cache[n - 1][j] > cache[n - 1][j - 1] ? cache[n - 1][j] : cache[n - 1][j - 1]) + triangle[n][j];
	}
}

int main()
{
	int max = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			scanf("%d", &triangle[i][j]);
	
	cache[0][0] = triangle[0][0];
	search(N-1);

	for (int i = 0; i < N; i++)
		if (max < cache[N - 1][i])
			max = cache[N - 1][i];

	printf("%d\n", max);

	return 0;
}
