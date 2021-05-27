#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void insertion_sort(char word[][100], int count)
{
    int i = 0, j = 0;
    char temp[100] = "";

    for (i = 1; i < count; i++)
    {
        strcpy(temp, word[i]);

        for (j = i - 1; j >= 0 && strlen(word[j]) < strlen(temp); j--)
            strcpy(word[j + 1], word[j]);

        strcpy(word[j + 1], temp);
    }

    return;
}

int main()
{
    char str[100] = "";
    char temp[100] = "";
    char word[100][100] = { 0 };
    int i = 0, j = 0, count = 0;

    fgets(str, 100, stdin);

    for (i = 0; i < strlen(str) - 1; i++)
    {
        if (str[i] == ' ')
        {
            j = 0;
            count++;
        }
        else
        {
            word[count][j] = str[i];
            j++;
        }
    }

    insertion_sort(word, count + 1);

    printf("%d\n", strlen(str));

    for (i = 0; i < count + 1; i++)
        if (strlen(word[i]) == strlen(word[0]))
            printf("%s ", word[i]);

    return 0;
}