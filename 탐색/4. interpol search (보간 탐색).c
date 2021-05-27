#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int interpol_search(int list[], int key, int low, int high)   // 이진 탐색은 정렬된 리스트에만 사용
{
    int s = 0;

    // key는 반드시 list[low] <= key <= list[high] 범위에 있어야 한다
    while (list[low] <= key && key <= list[high]) 
    {
        // 찾는 값 key의 인덱스를 s라고 한다면 (key = list[s])
        // (high - low):(s - low) = (list[high] - list[low]):(key - list[low])
        // (key - list[low])(high - low) = (list[high] - list[low])(s - low)
        s = (double)((key - list[low]) / (list[high] - list[low]) * (high - low) + low);

        
        if (key == list[s])         // 탐색 성공
            return s;
        else if (key < list[s])     // 왼쪽 부분리스트 탐색
            high = s - 1;
        else                        // 오른쪽 부분리스트 탐색
            low = s + 1;
    }

        return -1;  // 탐색 실패
}

void insertion_sort(int list[], int n)
{
    int i = 0, j = 0, temp = 0, key = 0;

    for (i = 1; i < n; i++)
    {
        key = list[i];

        for (j = i - 1; j >= 0 && list[j] > key; j--)
            list[j + 1] = list[j];

        list[j + 1] = key;
    }
}

int main()
{
    int list[] = { 9, 2, 4, 5, 1 };
    int size = sizeof(list) / sizeof(list[0]); // size는 원소의 개수
    int key = 0, low = 0, high = size - 1;

    printf("찾고싶은 값: ");
    scanf("%d", &key);

    printf("\n\n원래 배열: ");
    for (int i = 0; i < size; i++)
        printf("%d ", list[i]);

    insertion_sort(list, size);
    int answer = interpol_search(list, key, low, high);

    printf("\n\n정렬 배열: ");
    for (int i = 0; i < size; i++)
        printf("%d ", list[i]);

    if (answer == -1)
        printf("\n\n%d는 list에 없습니다.", key);
    else
        printf("\n\n%d는 정렬된 list[%d]에 있습니다.\n", key, answer);

    return 0;
}