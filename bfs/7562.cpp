#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <iostream>

#pragma warning(disable:4996)


using namespace std;

queue<pair<pair<int,int>,int>> Queue;
int TEST;
int Field[500][500] = { 0 };
int L, X, Y, CNT;
int result[1000] = { 0 };

void in_queue(int x, int y, int cnt)
{
	pair<pair<int, int>, int> n;
	n.first.first = x;
	n.first.second = y;
	n.second = cnt;
	Queue.push(n);
	Field[y][x] = -1;
}

void search()
{
	while (!Queue.empty()) {
		pair<pair<int, int>, int> tmp = Queue.front();
		Queue.pop();
		int x = tmp.first.first;
		int y = tmp.first.second;
		int cnt;
		CNT = cnt = tmp.second;

		if (x == X && y == Y)
			break;

		if (x + 1 < L && y + 2 < L && Field[y + 2][x + 1] != -1)
			in_queue(x + 1, y + 2, cnt + 1);
		if (x + 2 < L && y + 1 < L && Field[y + 1][x + 2] != -1)
			in_queue(x + 2, y + 1, cnt + 1);
		if (x + 2 < L && y - 1 >= 0 && Field[y - 1][x + 2] != -1)
			in_queue(x + 2, y - 1, cnt + 1);
		if (x + 1 < L && y - 2 >= 0 && Field[y - 2][x + 1] != -1)
			in_queue(x + 1, y - 2, cnt + 1);
		if (x - 1 >= 0 && y - 2 >= 0 && Field[y - 2][x - 1] != -1)
			in_queue(x - 1, y - 2, cnt + 1);
		if (x - 2 >= 0 && y - 1 >= 0 && Field[y - 1][x - 2] != -1)
			in_queue(x - 2, y - 1, cnt + 1);
		if (x - 2 >= 0 && y + 1 < L && Field[y + 1][x - 2] != -1)
			in_queue(x - 2, y + 1, cnt + 1);
		if (x - 1 >= 0 && y + 2 < L && Field[y + 2][x - 1] != -1)
			in_queue(x - 1, y + 2, cnt + 1);
	}
	while (!Queue.empty())
		Queue.pop();
}

int main()
{
	int i, j, t;

	setbuf(stdout, NULL);
	scanf("%d", &TEST);

	for (t = 0; t < TEST; t++) {
		for (i = 0; i < 500; i++)
			for (j = 0; j < 500; j++)
				Field[i][j] = 0;
		L = X = Y = CNT = 0;
		scanf("%d", &L);
		scanf("%d %d", &j, &i);
		in_queue(j, i, 0);
		scanf("%d %d", &X, &Y);
		Field[Y][X] = 1;

		search();

		printf("%d\n", CNT);
		CNT = 0;
	}


	return 0;
}
