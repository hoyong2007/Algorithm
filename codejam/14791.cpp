#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#pragma warning(disable: 4996)

using namespace std;


int T;
stack<char> num;
stack<char> num2;

int main()
{
	char tmp, ch1, ch2;

	scanf("%d", &T);
	getchar();

	for (int t_case = 0; t_case < T; t_case++) {
		while ('\n' != (tmp = getchar()))
			num.push(tmp);

		ch1 = ch2 = '9'+2;
		while (!num.empty()) {
			ch1 = num.top();
			num.pop();
			if (ch1 <= ch2)
				num2.push(ch2);
			else if (ch1 > ch2) {
				num2.push('9');
				ch1--;
			}
			ch2 = ch1;
		}
		num2.push(ch2);
		
		int flag = 1;
		printf("Case #%d: ", t_case+1);
		while (!num2.empty()) {
			if (flag && num2.top() == '0') 
				flag--;
			else if (num2.top() >= '0' && num2.top() <= '9') {
				if (num2.top() != '9')
					printf("%c", num2.top());
				else {
					while (!num2.empty() && num2.top() >= '0' && num2.top() <= '9') {
						printf("9");
						num2.pop();
					}
					num2.push(tmp);
				}
			}
			num2.pop();
		}
		printf("\n");
	}

	return 0;
}
