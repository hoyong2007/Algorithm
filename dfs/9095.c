#include <stdio.h>
#include <stdlib.h>

int CNT[1000] = {0};
int cnt;

void search(int num, int tmp)
{
	if (tmp > num)
		return;

	if (tmp == num) {
		cnt++;
		return;
	}

	if (tmp+1 <= num)
		search(num, tmp+1);
	if (tmp+2 <= num)
		search(num, tmp+2);
	if (tmp+3 <= num)
		search(num, tmp+3);
}


int main()
{
	int t_case, t = 0;
	int num = 0;
	int i;
	
	setbuf(stdout, NULL);
	scanf("%d", &t_case);

	for (t=0 ; t<t_case ; t++) {
		scanf("%d", &num);
		cnt = 0;
		search(num, 1);
		search(num, 2);
		search(num, 3);
		CNT[t] = cnt;
	}

	for (t=0 ; t<t_case ; t++)
		printf("%d\n", CNT[t]);


	return 0;
}
