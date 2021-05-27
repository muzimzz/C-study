#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void insertion_sort(double list[], int n)
{
    int i = 0, j = 0;
    double temp = 0;

    for (i = 1; i < n; i++)
    {
        temp = list[i];

        for (j = i - 1; j >= 0 && list[j] < temp; j--)
            list[j + 1] = list[j];

        list[j + 1] = temp;
    }

    return;
}

int main()
{
    int size = 0, i = 0, j = 0;
    double temp = 0;
    fscanf(stdin, "%d", &size);

    int score[100][3] = { 0 };
    double avg[100] = { 0 };

    for (i = 0; i < size; i++)
        for (j = 0; j < 3; j++)
            fscanf(stdin, "%d", &score[i][j]);

    for (i = 0; i < size; i++)
        avg[i] = (double)(score[i][0] + score[i][1] + score[i][2]) / 3.0;

    insertion_sort(avg, size);

    for (i = 0; i < size; i++)
        printf("%.1lf\n", avg[i]);

    return 0;
}