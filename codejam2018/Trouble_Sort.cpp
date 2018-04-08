#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

int T, N, CNT = 0;
int numE[100000] = { 0 };
int numO[100000] = { 0 };


int main()
{
	int i, idx;
	int sizeE, sizeO;
	scanf("%d", &T);

	for (int t_case = 0; t_case < T; t_case++) {
		scanf("%d", &N);

		sizeE = sizeO = 0;
		for (i = 1; i <= N; i++)
			scanf("%d", i % 2 ? &numO[sizeO++] : &numE[sizeE++]);


		std::sort(numO, numO + sizeO);
		std::sort(numE, numE + sizeE);


		sizeE = sizeO = 0;
		idx = -1;
		for (i = 1; i < N; i++) {
			if (i % 2 == 0) {
				if (numO[sizeO] < numE[sizeE++]) {
					idx = i - 1;
					i = N;
				}
			}
			else {
				if (numO[sizeO++] > numE[sizeE]) {
					idx = i - 1;
					i = N;
				}
			}
		}


		if (idx == -1)
			printf("Case #%d: OK\n", t_case + 1);
		else
			printf("Case #%d: %d\n", t_case + 1, idx);
	}

	return 0;
}
