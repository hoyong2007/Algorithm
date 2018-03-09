#include <stdio.h>
#include <stdlib.h>

int cnt[1000] = {0};
int M, N, Cabbage = 0;
int Field[500][500] = {0};

void search(int x, int y)
{
	if (Field[x][y] == 1) {
		Field[x][y] = 0;

		if (y<N && Field[x][y+1] == 1)
			search(x, y+1);

		if (x<M && Field[x+1][y] == 1)
			search(x+1, y);
		
		if (y>0 && Field[x][y-1] == 1)
			search(x, y-1);
		
		if (x>0 && Field[x-1][y] == 1)
			search(x-1, y);
	}
}


int main()
{
	int t_case, t = 0;
	int x, y;
	int i, j;

	setbuf(stdout, NULL);
	scanf("%d", &t_case);

	for (t=0 ; t<t_case ; t++) {
		scanf("%d %d %d", &M, &N, &Cabbage);

		// Init Field
		for (i=0 ; i<500 ; i++)
			for (j=0 ; j<500 ; j++)
				Field[i][j] = 0;

		for (i=0 ; i<Cabbage ; i++) {
			scanf("%d %d", &x, &y);
			Field[x][y] = 1;
		}

		for (x=0 ; x<M ; x++)
			for (y=0 ; y<N ; y++)
				if (Field[x][y] == 1) {
					search(x, y);
					cnt[t]++;
				}
	}

	for (t=0 ; t<t_case ; t++)
		printf("%d\n", cnt[t]);


	return 0;
}
