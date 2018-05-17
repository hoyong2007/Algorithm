#include <iostream>
#include <cmath>

#pragma warning(disable:4996)

using namespace std;

int T, t_case;
int N;
unsigned long long p[100] = { 0 };
unsigned int factor[100][2] = { 0 };



int miller_rabin(int n, int b, int s, int t)
{
	if ((unsigned long long)pow(b, t) % n == 1)
		return 1;
	else {
		int exp = 1;
		unsigned long long mod = 0;
		for (int i = 0; i <= s ; i++, exp *= 2) {
			mod = (unsigned long long)pow(b, exp*t) % n;
			if (mod == n - 1)
				return 1;
		}
		return 0;
	}
}


int is_prime(int n) {
	int s = 0, t = n - 1;
	while (1) {
		if (t % 2 != 0)
			break;
		t = t >> 1;
		s += 1;
	}
	for (int i = 2; i < 10 && i<n-1 ; i++) {
		if (!miller_rabin(n, i, s, t))
			return 0;
	}
	return 1;
}


unsigned int found_111(int n) 
{
	int rest;
	int b, i, max=100;
	for (b = 2; b < n; b++) {
		rest = n - 1;
		for (i = 1; i<max ; i++) {
			rest -= pow(b, i);
			if (rest == 0)
				return b;
			else if (rest < 0) {
				max = i;
				break;
			}
		}
	}
	return 0;
}



int main()
{
	int rest, exp, mul = 0, b = 2;
	int i, idx;;
	unsigned long long tmp;
	unsigned int ret;

	setbuf(stdout, NULL);

	scanf("%d", &T);

	for (t_case = 0; t_case < T; t_case++) {
		scanf("%d", &N);

		rest = N;
		for (i = 0; i < 100; i++) 
			factor[i][0] = factor[i][1] = 0;
		idx = 0;
		//printf("%d is prime? %d\n", N, is_prime(N));

		if (!is_prime(N)) {
			for (i = 2; i<N/2 ; i++) {
				if (N%i == 0) {
					if (N / i <= i + 1)
						break;
					factor[idx][0] = N / i;
					factor[idx][1] = i; 
					idx++;
				}
			}
			for (i = idx - 1; i >= 0; i--) {
				ret = found_111(factor[i][0]);
				if (ret) {
					printf("Case #%d\n%d\n", t_case + 1, ret);
					break;
				}
				printf("Something wrong!!\n");
			}
		}
		else {
			ret = found_111(N);
			if (ret) {
				printf("Case #%d\n%d\n", t_case + 1, ret);
			}
			else
				printf("Something wrong!!\n");
		}
	}

	return 0;
}
