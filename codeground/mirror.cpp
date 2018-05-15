#include <iostream>

#pragma warning(disable:4996)
#define EAST 0
#define WEST 1
#define SOUTH 2
#define NORTH 3
using namespace std;


struct vec {
	pair<int, int> east;
	pair<int, int> west;
	pair<int, int> south;
	pair<int, int> north;
};


int T, t_case;
int room[1100][1100] = { 0 };
int N;
pair<int, int> light = make_pair(0, 0);


int main()
{
	int i, j;
	int x, y;
	int way, result;
	char tmp;
	struct vec mirror[3];

	mirror[2].east	= make_pair(0, 1);
	mirror[2].west	= make_pair(0, -1);
	mirror[2].south = make_pair(1, 0);
	mirror[2].north = make_pair(-1, 0);
	mirror[1].east	= make_pair(0,-1);
	mirror[1].west	= make_pair(0, 1);
	mirror[1].south = make_pair(-1, 0);
	mirror[1].north = make_pair(1, 0);

	scanf("%d", &T);

	for (t_case = 0; t_case < T; t_case++) {
		way = EAST;
		result = 0;
		light = make_pair(0, 0);
		scanf("%d", &N);

		//getchar();
		for (i = 0; i < N; i++) 
			for (j = 0; j < N; j++) {
				do {
					scanf("%c", &tmp);
				} while (tmp < '0' || tmp>'2');
				room[i][j] = tmp % '0';
			}
		
		while (1) {
			x = light.first;
			y = light.second;
			if (x < 0 || x > N || y < 0 || y > N)
				break;
			if (way == EAST) {
				if (room[y][x]%3 == 0) {
					light.first += 1;
				}
				else {
					if (room[y][x] % 3 == 1) {
						if (room[y][x] == 1) {
							result++;
							room[y][x] += 3;
						}
						way = NORTH;
					}
					else if (room[y][x] % 3 == 2) {
						if (room[y][x] == 2) {
							result++;
							room[y][x] += 3;
						}
						way = SOUTH;
					}
					light.first += mirror[room[y][x]%3].east.first;
					light.second += mirror[room[y][x]%3].east.second;
				}
				
			}
			else if (way == WEST) {
				if (room[y][x]%3 == 0) {
					light.first -= 1;
				}
				else {
					if (room[y][x] % 3 == 1) {
						if (room[y][x] == 1) {
							result++;
							room[y][x] += 3;
						}
						way = SOUTH;
					}
					else if (room[y][x] % 3 == 2) {
						if (room[y][x] == 2) {
							result++;
							room[y][x] += 3;
						}
						way = NORTH;
					}
					light.first += mirror[room[y][x]%3].west.first;
					light.second += mirror[room[y][x]%3].west.second;
				}
			}
			else if (way == SOUTH) {
				if (room[y][x]%3 == 0) {
					light.second += 1;
				}
				else {
					if (room[y][x] % 3 == 1) {
						if (room[y][x] == 1) {
							result++;
							room[y][x] += 3;
						}
						way = WEST;
					}
					else if (room[y][x] % 3 == 2) {
						if (room[y][x] == 2) {
							result++;
							room[y][x] += 3;
						}
						way = EAST;
					}
					light.first += mirror[room[y][x]%3].south.first;
					light.second += mirror[room[y][x]%3].south.second;
				}
			}
			else if (way == NORTH) {
				if (room[y][x]%3 == 0) {
					light.second -= 1;
				}
				else {
					if (room[y][x] % 3 == 1) {
						if (room[y][x] == 1) {
							result++;
							room[y][x] += 3;
						}
						way = EAST;
					}
					else if (room[y][x] % 3 == 2) {
						if (room[y][x] == 2) {
							result++;
							room[y][x] += 3;
						}
						way = WEST;
					}
					light.first += mirror[room[y][x]%3].north.first;
					light.second += mirror[room[y][x]%3].north.second;
				}
			}
		}
		printf("Case #%d\n", t_case + 1);
		printf("%d\n", result);
	}

	return 0;
}
