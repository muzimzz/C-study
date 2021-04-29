#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int i = 0, j = 0;

void print(int *n, int input)
{
    int temp = 0;

    for (i = 0; i < input - 1; i++)
        for (j = 0; j < input - 1; j++)
        {
            if (n[j] > n[j + 1])
            {
                temp = n[j];
                n[j] = n[j + 1];
                n[j + 1] = temp;
            }
        }

    for (i = 0; i < input; i++)
        printf("%d ", n[i]);
}

int main()
{
    int input = 0;
    scanf("%d", &input);
    int n[SIZE] = { 0 };

    for (i = 0; i < input; i++)
        scanf("%d", &n[i]);

    print(n, input);

    return 0;
}