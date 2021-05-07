
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 8

typedef struct {		// 미로
	short r;
	short c;
} element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택의 초기화
void init_stack(StackType* s)
{
	s->top = -1;
}

// 스택이 empty인지 검사
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 스택이 full인지 검사
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 스택에 원소 추가
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택이 포화상태입니다.\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// top 리턴하고 제거하기
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 공백상태입니다.\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// top 리턴하기
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 공백상태입니다.\n");
		exit(1);
	}
	else return s->data[s->top];
}

// 미로 함수

element here = { 1,0 }, entry = { 1,0 };

//char maze[MAZE_SIZE][MAZE_SIZE] = {
//	{ '1', '1', '1', '1', '1', '1' },
//{ 'e', '0', '1', '0', '0', '1' },
//{ '1', '0', '0', '0', '1', '1' },
//{ '1', '0', '1', '0', '1', '1' },
//{ '1', '0', '1', '0', '0', 'x' },
//{ '1', '1', '1', '1', '1', '1' },
//};
int maze[MAZE_SIZE][MAZE_SIZE] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1},
	{ 0, 0, 0, 0, 0, 1, 0, 1},
	{ 1, 0, 1, 1, 1, 1, 0, 1},
	{ 1, 0, 1, 1, 0, 0, 0, 1},
	{ 1, 0, 0, 0, 0, 1, 1, 1},
	{ 1, 0, 1, 0, 1, 0, 1, 1},
	{ 1, 0, 1, 0, 0, 0, 0, INT_MAX },
	{ 1, 1, 1, 1, 1, 1, 1, 1},
};

void push_loc(StackType* s, int r, int c)
{
	if (r < 0 || c < 0) return;
	if (maze[r][c] == 0 || maze[r][c] == INT_MAX) {
		//if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}
// 미로 출력 
void maze_print(int maze[MAZE_SIZE][MAZE_SIZE])
{
	//printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			if (maze[r][c] == INT_MAX)
				printf("%3c", 'x');
			else if (maze[r][c] == 2)
				printf("%3c", 'e');
			else
				printf("%3d", maze[r][c]);
		}
		printf("\n");
	}
	printf("\n\n\n");
}

void get_max_step(element current, element* next) {

	int r = current.r;
	int c = current.c;

	element max = current;
	element up = { r - 1, c };
	element down = { r + 1, c };
	element left = { r, c - 1 };
	element right = { r, c + 1 };

	if (current.r != 0)
		max = maze[up.r][up.c] > maze[max.r][max.c] ? up : max;
	if (current.r != MAZE_SIZE - 1)
		max = maze[down.r][down.c] > maze[max.r][max.c] ? down : max;
	if (current.c != 0)
		max = maze[left.r][left.c] > maze[max.r][max.c] ? left : max;
	if (current.c != MAZE_SIZE - 1)
		max = maze[right.r][right.c] > maze[max.r][max.c] ? right : max;

	*next = max;	
}

void path(int maze[MAZE_SIZE][MAZE_SIZE]) {
	element next;
	here = entry;
	printf("미로 경로: ");
	while (maze[here.r][here.c] != INT_MAX) {
		printf("(%d,%d)", here.r, here.c);
		get_max_step(here, &next);
		here = next;
	}
	printf("(%d,%d)\n", here.r, here.c);
}

int steps = 2;

int main(void)
{
	int r, c;
	StackType s;

	printf("초기 미로 상태:\n")
	maze_print(maze);
	init_stack(&s);
	here = entry;
	while (maze[here.r][here.c] != INT_MAX) {
		r = here.r;
		c = here.c;
		maze[r][c] = steps++;
		//maze_print(maze);
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);
		if (is_empty(&s)) {
			printf("탐색 실패\n");
			return;
		}
		else
			here = pop(&s);
	}
	printf("미로 경로 출력\n");
	maze_print(maze);
	printf("탐색성공\n");
	path(maze);

	return 0;
}
