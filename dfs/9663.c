#include <stdio.h>
#include <string.h>

int Field[20][20] = {0};
int N, CNT=0;

void debug()
{
	int i, j;
	for (i=0 ; i<N ; i++) {
		for(j=0 ; j<N ; j++)
			printf(" %d", Field[i][j]);
		printf("\n");
	}
}


void check(int x, int y)
{
	int i, j;

	for (i=x-1,j=y-1 ; i>=0 && j>=0 ; i--,j--) {
		Field[j][i]++;
	}
	for (i=x-1,j=y+1 ; i>=0 && j<N ; i--,j++) {
		Field[j][i]++;
	}
	for (i=x+1,j=y-1 ; i<N && j>=0 ; i++,j--) {
		Field[j][i]++;
	}
	for (i=x+1,j=y+1 ; i<N && j<N ; i++,j++) {
		Field[j][i]++;
	}
	for (i=0,j=y ; i<N ; i++) {
		Field[j][i]++;
	}
	for (i=x,j=0 ; j<N ; j++) {
		Field[j][i]++;
	}
	Field[y][x]--;
}

void uncheck(int x, int y)
{
	int i, j;

	for (i=x-1,j=y-1 ; i>=0 && j>=0 ; i--,j--) {
		Field[j][i]--;
	}
	for (i=x-1,j=y+1 ; i>=0 && j<N ; i--,j++) {
		Field[j][i]--;
	}
	for (i=x+1,j=y-1 ; i<N && j>=0 ; i++,j--) {
		Field[j][i]--;
	}
	for (i=x+1,j=y+1 ; i<N && j<N ; i++,j++) {
		Field[j][i]--;
	}
	for (i=0,j=y ; i<N ; i++) {
		Field[j][i]--;
	}
	for (i=x,j=0 ; j<N ; j++) {
		Field[j][i]--;
	}
	Field[y][x]++;
}


void search(int x, int y)
{
	int i;

	check(x, y);
	for (i=0 ; i<N ; i++)
		if (Field[y+1][i] == 0) {
			if (y+2 == N) {
				CNT++;
				uncheck(x, y);
				return;
			}
			search(i, y+1);
		}
	uncheck(x, y);
		
}


int main()
{
	int x, y;
	int i, j;

	setbuf(stdout, NULL);
	scanf("%d", &N);

	if (N==1) {
		printf("1\n");
		return 0;
	}

	// Init Field
	memset(Field, 0, sizeof(Field));
	
	for (i=0 ; i<N ; i++) {
		search(i, 0);
	}

	printf("%d\n", CNT);
	

	return 0;
}
