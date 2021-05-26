#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int list[] = { 5, 2, 9, 1, 3 };

int seq_search2(int key, int low, int high)
{
    int i = 0;

    list[high + 1] = key;

    for (i = low; list[i] != key; i++); // key를 찾으면 바로 빠져나옴 (i증가 x)

    if (i == high + 1)
        return -1; // 탐색 실패
    else
        return i;  // 탐색 성공
}

int main()
{
    int key = 0, low = 0, high = sizeof(list) / sizeof(list[0]) - 1;

    printf("찾고싶은 값: ");
    scanf("%d", &key);

    int answer = seq_search2(key, low, high);

    if (answer == -1)
        printf("%d는 list에 없습니다.", key);
    else
        printf("%d는 list[%d]에 있습니다.", key, answer);

    return 0;
}