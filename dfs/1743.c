#include <stdio.h>
#include <string.h>

int Size = 0;
int Max = 0;
int M, N, Garbage = 0;
int Field[200][200] = {0};

void search(int x, int y)
{
	if (Field[x][y] == 1) {
		Size++;
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
	int x, y;
	int i, j;

	setbuf(stdout, NULL);
	scanf("%d %d %d", &M, &N, &Garbage);

	// Init Field
	memset(Field, 0, sizeof(Field));
	
	for (i=0 ; i<Garbage ; i++) {
		scanf("%d %d", &x, &y);
		Field[x][y] = 1;
	}

	
	for (x=1 ; x<=M ; x++)
		for (y=1 ; y<=N ; y++)
			if (Field[x][y] == 1) {
				search(x, y);
				if (Size > Max)
					Max = Size;
				Size = 0;
			}

	printf("%d\n", Max);
	

	return 0;
}
