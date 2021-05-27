#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

//void insertion_sort(char choice[], int count)
//{
//    int i = 0, j = 0;
//    char temp[100] = "";
//
//    for (i = 1; i < count; i++)
//    {
//        strcpy(temp, choice[i]);
//
//        for (j = i - 1; j >= 0 && strcmp(choice[j], temp) > 0; j--)
//            strcpy(choice[j + 1], choice[j]);
//
//        strcpy(choice[j + 1], temp);
//    }
//
//    return;
//}

int main()
{
    char word[10][100] = { 0 };
    char choice[10][100] = { 0 };
    char temp[100] = "";
    int i = 0, j = 0, count = 0;
    char n = '\0';

    for (i = 0; i<10; i++)
        fgets(word[i], 100, stdin);

    fscanf(stdin, "%c", &n);

    for (i = 0; i < 10; i++)
        if (strchr(word[i], n))
        {
            strcpy(choice[count], word[i]);
            count++;
        }

    for (i = 1; i < count; i++)
    {
        strcpy(temp, choice[i]);

        for (j = i - 1; j >= 0 && strcmp(choice[j], temp) > 0; j--)
            strcpy(choice[j + 1], choice[j]);

        strcpy(choice[j + 1], temp);
    }

    for (i = 0; i < count; i++)
        printf("%s", choice[i]);

    return 0;
}