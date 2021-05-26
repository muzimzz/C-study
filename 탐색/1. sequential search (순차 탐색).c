#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int list[] = { 5, 2, 9, 1, 3 };

int seq_search(int key, int low, int high)
{
    int i = 0;
    for (i = low; i <= high; i++)
        if (list[i] == key)
            return i;
    
    return -1;
}

int main()
{
    int key = 0, low = 0, high = sizeof(list) / sizeof(list[0]) - 1;

    printf("찾고싶은 값: ");
    scanf("%d", &key);

    int answer = seq_search(key, low, high);

    if (answer == -1)
        printf("%d는 list에 없습니다.", key);
    else
        printf("%d는 list[%d]에 있습니다.", key, answer);

    return 0;
}