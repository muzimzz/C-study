#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int main()
{
    int i = 0, j = 0;
    char input[SIZE]; // 입력받을 문장
    char word[SIZE][SIZE]; // 단어 저장
    int wcnt = 0; // word count, 공백의 개수

    gets(input);

    while (i < strlen(input) && input[i] == ' ')
        i++;  // 문자열 처음에 등장하는 공백 제외

    for (; i < strlen(input); i++) // 공백이 아니라면 word에 저장
    {
        if (input[i] != ' ')
            word[wcnt][j++] = input[i];
        // for문에서 i를 증가시키고 있으므로 input[i++]을 쓰면 안됨

        else if (input[i + 1] != ' ' && input[i + 1])
        {
            word[wcnt++][j] = 0; // 해당 단어의 끝을 \0로 만들고
            j = 0;               // 다음 단어로 이동, j = 0
        }
    }
    // input의 마지막이라면 for문 종료 
    word[wcnt++][j] = 0; // 마지막 단어의 끝을 \0으로 만든다
    
    for (i = 0; i < wcnt; i++)
        printf("%s\n", word[i]);

    return 0;
}