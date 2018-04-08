#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#pragma warning(disable: 4996)

using namespace std;

int T;
unsigned int D;
unsigned int strength = 1;
unsigned int damage = 0;
int CNT = 0;
char P[50] = { 0 };

void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

int try_dec()
{
	int flag = 1;
	char tmp;
	for (int i = strlen(P) - 1 ; i >= 0; i--) {
		if (P[i] == 'S') {
			flag = 0;
		}
		else if (!flag && P[i] == 'C') {
			swap(&P[i], &P[i+1]);
			CNT++;
			return 1;
		}
	}
	return 0;
}

void calc_dmg()
{
	damage = 0;
	strength = 1;
	for (int i = 0; i < strlen(P); i++) {
		if (P[i] == 'C')
			strength *= 2;
		else if (P[i] == 'S')
			damage += strength;
	}
}


int main()
{
	int t_case;
	int i, j;
	char tmp;
	scanf("%d", &T);

	for (t_case = 0; t_case < T; t_case++) {
		CNT = damage = 0;
		scanf("%d", &D);
		getchar();

		scanf("%s", P);
		calc_dmg();

		while (D < damage) {
			if (!try_dec())
				break;
			calc_dmg();
		}
		calc_dmg();
		if (D < damage)
			printf("Case #%d: IMPOSSIBLE\n", t_case + 1);
		else
			printf("Case #%d: %d\n", t_case + 1, CNT);

	}

	return 0;
}
