#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_ELEMENT 100

typedef struct {
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType* create()  // 생성
{
    return (HeapType*)malloc(sizeof(HeapType*));
}

void init(HeapType* h) // 초기화
{
    h->heap_size = 0;
}

int is_full(HeapType* h)
{
    if (h->heap_size == MAX_ELEMENT)
        return 1;
    else
        return 0;
}

int is_empty(HeapType* h)
{
    if (h->heap_size == 0)
        return 1;
    else
        return 0;
}

void insert_max_heap(HeapType* h, element item) // max_heap에 item 삽입
{
    if (is_full(h))
    {
        printf("힙이 포화상태입니다.\n");
        return;
    }

    int i = 0;
    i = ++(h->heap_size); // i를 heap[마지막 인덱스 + 1]에 삽입

    // 부모노드까지 거슬러 올라가거나 더 큰 부모를 만나면 종료
    while ((i != 1) && (item.key > h->heap[i / 2].key))
    {
        h->heap[i] = h->heap[i / 2];    // 부모의 값을 자식으로 내리고
        i /= 2; // 부모인덱스 기준으로 탐색
    }

    h->heap[i] = item;
}

element delete_max_heap(HeapType* h) // 제일 큰 값(루트) 삭제
{
    if (is_empty(h))
    {
        printf("힙이 공백상태입니다.\n");
        return;
    }

    int parent = 0, child = 0;
    element item, temp;

    item = h->heap[1];  // 반환할 루트값을 item에 저장
    temp = h->heap[(h->heap_size)--];   // 마지막 인덱스값을 temp에 저장
    parent = 1;
    child = 2;  

    while (child <= h->heap_size)   // 마지막 노드를 만날때까지
    {
        if ((child < h->heap_size) &&   // 왼쪽자식 < 오른쪽 자식이면 오른쪽과 비교
            (h->heap[child].key < h->heap[child + 1].key))
            child++;

        if (h->heap[child].key <= temp.key) // 자식이 temp보다 작으면 종료
            break;
       
        h->heap[parent] = h->heap[child];   // 부모 자리에 자식 삽입
        parent = child;
        child *= 2;        // 자식의 서브트리 기준으로 탐색
    }

    h->heap[parent] = temp;

    return item;
}

void print_heap(HeapType* h)
{
    int i = 0;
    for (i = 1; i <= h->heap_size; i++) // 힙의 0번 인덱스는 NULL
        printf("%d ", h->heap[i].key);
}

int main()
{
    int i = 0;
    element item[20];
    HeapType* heap = create(); 
    // HeapType* heap = (HeapType*)malloc(sizeof(HeapType*);
    init(heap);

    for (i = 0; i < 10; i++)
    {
        printf("max heap에 삽입할 수를 입력하세요: ");
        scanf("%d", &item[i].key);

        insert_max_heap(heap, item[i]);
    }

    print_heap(heap);
    printf("\n\n");

    for (i = 10; i < 15; i++)   
    {
        item[i] = delete_max_heap(heap);
        printf("max heap에서 삭제된 수: %d\n", item[i].key);
    }

    print_heap(heap);

    return 0;
}