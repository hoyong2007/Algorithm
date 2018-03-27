#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>

#pragma warning(disable:4996)

using namespace std;

queue<pair<int, int>> Queue;	// <x,time>
int Field[200000] = { 0 };
int FROM, TO, TIME;


void in_queue(int x, int time)
{
	pair<int, int> n;
	n.first = x;
	n.second = time;
	Queue.push(n);
	Field[x] = 1;
}


void search()
{
	while (!Queue.empty()) {
		pair<int, int> tmp = Queue.front();
		Queue.pop();
		int x = tmp.first;
		int time;
		TIME = time = tmp.second;

		if (TO == x)
			break;

		if (2 * x < 200000 && Field[2 * x] == 0)
			in_queue(2 * x, time + 1);
		if (x + 1 < 200000 && Field[x + 1] == 0)
			in_queue(x + 1, time + 1);
		if (x - 1 >= 0 && Field[x - 1] == 0)
			in_queue(x - 1, time + 1);
	}
	while (!Queue.empty())
		Queue.pop();
}

int main()
{
	setbuf(stdout, NULL);
	scanf("%d %d", &FROM, &TO);

	in_queue(FROM, 0);

	search();

	printf("%d\n", TIME);

	return 0;
}
