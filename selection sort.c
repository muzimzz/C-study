#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )
#define SIZE 5

int i = 0, j = 0;


void selection_sort(int* li, int n) 
{
    int least = 0, temp = 0;

    for (i = 0; i < n - 1; i++)  // 마지막 숫자는 자동으로 정렬
    {
        least = i;

        for (j = i + 1; j < n; j++)  // 최솟값 탐색
            if (li[j] < li[least])
                least = j; 
    
        if (i != least)  // 최솟값이 자기 자신이면 자료 이동 x
            SWAP(li[i], li[least], temp);      
    }

    return;
}

int main() 
{
    int n = SIZE;
    int li[SIZE] = { 0 };

    for (i = 0; i < n; i++)
        scanf("%d", &li[i]);

    selection_sort(li, n);

    for (i = 0; i < n; i++)
        printf("%d\n", li[i]);

    return 0;
}