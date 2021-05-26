#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int binary_search(int list[], int key, int low, int high)   // 이진 탐색은 정렬된 리스트에만 사용
{
    int middle = 0;

    while (low <= high) // 탐색할 리스트 값이 남아있는 경우
    {
        middle = ((low + high) / 2);    

        if (key == list[middle])        // 탐색 성공
            return middle;
        else if (key > list[middle])    // 왼쪽 부분리스트 탐색
            low = middle + 1;
        else  // key < list[middle]     // 오른쪽 부분리스트 탐색
            high = middle - 1;
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
    int list[] = { 5, 2, 9, 1, 3 };
    int key = 0, low = 0, high = sizeof(list) / sizeof(list[0]) - 1;

    printf("찾고싶은 값: ");
    scanf("%d", &key);

    printf("\n\n원래 배열: ");
    for (int i = 0; i <= high; i++)
        printf("%d ", list[i]);

    insertion_sort(list, high + 1);
    int answer = binary_search(list, key, low, high);

    printf("\n\n정렬 배열: ");
    for (int i = 0; i <= high; i++)
        printf("%d ", list[i]);

    if (answer == -1)
        printf("\n\n%d는 list에 없습니다.", key);
    else
        printf("\n\n%d는 정렬된 list[%d]에 있습니다.\n", key, answer);

    return 0;
}