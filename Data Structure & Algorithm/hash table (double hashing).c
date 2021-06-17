#define _CRT_SECURE_NO_WARNINGS

#define KEY_SIZE 10		// 탐색키의 최대 길이
#define TABLE_SIZE 13	// 해싱 테이블의 크기
#define DOUBLE_HASH_SIZE 11	// 이중 해싱에 사용되는 소수는 테이블 크기보다 한단계 작음

#define empty(item) (strlen(item.key) == 0)	// NULL이면 TRUE
#define equal(item1, item2) (!strcmp(item1.key, item2.key)) // 같으면 TRUE
// (strcmp(item1.key, item2.key) == 0)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char key[KEY_SIZE];	// NULL문자 포함해서 사실상 탐색키 최대 길이는 9
} element;

element hash_table[TABLE_SIZE];

void init_table(element ht[])
{
	int i = 0;

	for (i = 0; i < TABLE_SIZE; i++)
		ht[i].key[0] = NULL;

	return;
}

int transform(char* key)	// key(문자열)를 숫자로 변환하는 함수
{
	int num = 0;

	while (*key)			// *key = key[0], NULL 전까지 
		num += *key++;		// 각 문자의 아스키코드를 num에 더한다
							// 연산 순서: 후위연산자 > 포인터(*)연산자
	return num;
}

int hash_function(char* key)
{
	// 키를 숫자로 변환하고 테이블의 크기로 나눈 나머지 반환
	return transform(key) % TABLE_SIZE;
}

// dh: Double Hashing (이중 해싱)
void hash_dh_add(element item, element ht[]) // 테이블에 키를 삽입하는 함수
{
	int i = 0, hash_value = 0, step = 0;

	hash_value = i = hash_function(item.key);
	printf("%s의 hash_address = %d\n", item.key, i);

	while (!empty(ht[i]))	// 해당 주소(버켓)에 값이 이미 존재하면 선형탐사 실행
	{
		if (equal(item, ht[i]))
		{
			fprintf(stderr, "탐색키가 중복되었습니다.\n");
			exit(1);	// 입력값과 동일한 탐색키가 존재하면 종료
		}

		step = DOUBLE_HASH_SIZE - (hash_value % DOUBLE_HASH_SIZE);
		i = (i + step) % TABLE_SIZE;	// 다음 버켓 인덱스 탐색

		if (i == hash_value) // 한 바퀴를 모두 돌아왔을 경우
		{
			fprintf(stderr, "테이블이 가득찼습니다.\n");
			exit(1);	// 테이블이 가득 차 있으므로 종료
		}
	}

	ht[i] = item;	// 이중 해싱법을 이용해 키 삽입

	return;
}

void hash_dh_search(element item, element ht[])
{
	int i = 0, hash_value = 0, step = 0;

	hash_value = i = hash_function(item.key);

	while (!empty(ht[i]))	// 이중 해싱 중 비어있는 버켓을 만나면 탐색 실패
	{
		if (equal(item, ht[i])) // if (strcmp(item.key, ht[i].key) == 0)
		{
			printf("탐색 %s: 위치 = %d\n", item.key, i);
			return;
		}

		step = DOUBLE_HASH_SIZE - (hash_value % DOUBLE_HASH_SIZE);
		i = (i + step) % TABLE_SIZE;	// 다음 버켓 인덱스 탐색

		if (i == hash_value)	// 한 바퀴를 모두 돌아왔을 경우
		{
			fprintf(stderr, "찾는 값이 테이블에 없음\n");
			return;	// 테이블이 가득 차있으며 찾는 값이 없으므로 종료
		}
	}

	fprintf(stderr, "찾는 값이 테이블에 없음\n");

	return;
}

void hash_dh_print(element ht[])	// 해시 테이블 출력
{
	int i = 0;

	printf("\n===============================\n");
	for (i = 0; i < TABLE_SIZE; i++)
		printf("[%d] %s\n", i, ht[i].key);
	printf("===============================\n");
}

int main()
{
	char* fruit[7] = { "apple", "pear", "peach", "tomato", "lemon", "blueberry", "grape" };
	element e;

	for (int i = 0; i < 7; i++)
	{
		strcpy(e.key, fruit[i]);
		hash_dh_add(e, hash_table);
		hash_dh_print(hash_table);
	}

	for (int i = 0; i < 7; i++)
	{
		strcpy(e.key, fruit[i]);
		hash_dh_search(e, hash_table);
	}

	return 0;
}