#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <utility>
#pragma warning(disable:4996)

using namespace std;

int T, N;
//int cache[50] = { 0 };

vector<pair<int, int> > cache(50, make_pair(0,0));

pair<int,int> fibo(int n)
{
	if (n == 0) {
		cache[n] = make_pair(1,0);
		return make_pair(1,0);
	}
	else if (n == 1) {
		cache[n] = make_pair(0, 1);
		return make_pair(0,1);
	}
	else {
		if (cache[n - 1] == make_pair(0, 0)) {
			cache[n - 1] = fibo(n - 1);
		}
		if (cache[n - 2] == make_pair(0, 0)) {
			cache[n - 2] = fibo(n - 2);
		}
		cache[n] = make_pair(cache[n - 1].first + cache[n - 2].first, cache[n - 1].second + cache[n - 2].second);
		return cache[n];
	}
}

int main()
{
	scanf("%d", &T);

	for (int tcase = 0; tcase < T; tcase++) {
		scanf("%d", &N);
		fibo(N);
		printf("%d %d\n", cache[N].first, cache[N].second);
	}

	return 0;
}
