#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void is_this_primeNumber()
{
	int input = 0, i = 0;

		scanf("%d", &input);

		for (i = 2; i < input; i++)
		{
			if (input % i == 0)
			{
				printf("%d는 소수가 아닙니다.\n", input);
				break;
			}
		}

		if (i == input)
			printf("%d는 소수입니다.\n", input);

	
	return;
}

int main() 
{
	is_this_primeNumber();

	return 0;
}