#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 21

int main()
{
    char copy[] = "yoonserin"; // \0까지 size = 10
    char s1[SIZE];
    char s2[SIZE] = "my name is yoonserin";
    char s3[9];

    //strcpy(s1, copy); printf("s1: %s\n", s1);
    //strcpy(s2, copy); printf("s2: %s\n", s2);
    //// strcpy(s3, copy); s3의 size보다 copy의 size가 크므로 runtime error

    strncpy(s1, copy, 4); printf("s1: %s\n", s1);
    strncpy(s2, copy, 4); printf("s2(1): %s\n", s2);
    strncpy(s2, copy, sizeof(copy)); // strcpy(s1, copy)와 같다
    printf("s2(2): %s\n", s2);

    return 0;
}