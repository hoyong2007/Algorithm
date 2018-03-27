#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>

#pragma warning(disable:4996)

using namespace std;

queue<pair<pair<int, int>, int> > Queue;	// <<x,y>,day>
int Field[1500][1500] = { 0 };
int X, Y, DAY;


void in_queue(int x, int y, int cnt)
{
	pair<pair<int, int>, int> n;
	n.first.first = x;
	n.first.second = y;
	n.second = cnt;
	Queue.push(n);
	Field[y][x] = 1;
}


void search()
{
	while (!Queue.empty()) {
		pair<pair<int, int>, int> tmp = Queue.front();
		Queue.pop();
		int x = tmp.first.first;
		int y = tmp.first.second;
		int day;
		DAY = day = tmp.second;

		//debug();

		if (x + 1 < X && Field[y][x + 1] == 0)
			in_queue(x + 1, y, day + 1);
		if (y + 1 < Y && Field[y + 1][x] == 0)
			in_queue(x, y + 1, day + 1);
		if (x - 1 >= 0 && Field[y][x - 1] == 0)
			in_queue(x - 1, y, day + 1);
		if (y - 1 >= 0 && Field[y-1][x] == 0)
			in_queue(x, y - 1, day + 1);
	}
	while (!Queue.empty())
		Queue.pop();
}

int main()
{
	int i, j;

	setbuf(stdout, NULL);
	scanf("%d %d", &X, &Y);

	for (i = 0; i < Y; i++)
		for (j = 0; j < X; j++) {
			scanf("%d", &Field[i][j]);
			if (Field[i][j] == 1)
				in_queue(j, i, 0);
		}

	if (!Queue.empty())
		search();
	else
		DAY = -1;

	for (i = 0; i < Y; i++)
		for (j = 0; j < X; j++)
			if (Field[i][j] == 0)
				DAY = -1;

	printf("%d\n", DAY);
	


	return 0;
}
