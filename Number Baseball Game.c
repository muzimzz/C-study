#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define SIZE 4  // 정답은 네 자리 수

int i = 0, j = 0;               // for문에 쓰일 변수
int hint_count = 1;             // 힌트 사용 여부
int playerNumber = 0;           // 사용자가 입력한 네 자리 수
int playerAnswer[SIZE] = { 0 }; // 입력한 네 자리 수를 쪼개 배열에 저장
int answer[SIZE] = { 0 };       // 컴퓨터가 생성한 정답 배열

void printTutorial() // 규칙을 출력하는 함수
{
    char enter;

    printf("                        ■          ■   ■            ■   ■            ■   ■■■■■■      ■■■■■■■   ■■■■■\n");
    printf("                        ■■        ■   ■            ■   ■■        ■■   ■          ■    ■               ■        ■\n");
    printf("                        ■  ■      ■   ■            ■   ■  ■    ■  ■   ■          ■    ■               ■        ■\n");
    printf("                        ■    ■    ■   ■            ■   ■     ■     ■   ■■■■■■      ■■■■■■■   ■■■■■■■\n");
    printf("                        ■      ■  ■   ■            ■   ■            ■   ■          ■    ■               ■           ■\n");
    printf("                        ■        ■■   ■            ■   ■            ■   ■          ■    ■               ■           ■\n");
    printf("                        ■          ■   ■■■■■■■■   ■            ■   ■■■■■■      ■■■■■■■   ■           ■\n");
    printf("\n\n");
    printf("         ■■■■■■             ■          ■■■■■■■   ■■■■■■■   ■■■■■■             ■          ■               ■\n");
    printf("         ■          ■         ■  ■        ■               ■               ■          ■         ■  ■        ■               ■\n");
    printf("         ■          ■       ■      ■      ■               ■               ■          ■       ■      ■      ■               ■                      ■   ■   ■■■   ■■■\n");
    printf("         ■■■■■■        ■■■■■■     ■■■■■■■   ■■■■■■■   ■■■■■■        ■■■■■■     ■               ■                      ■  ■    ■   ■  ■\n");
    printf("         ■          ■     ■          ■                ■   ■               ■          ■     ■          ■    ■               ■                      ■■      ■■■   ■\n");
    printf("         ■          ■    ■            ■               ■   ■               ■          ■    ■            ■   ■               ■                      ■  ■    ■       ■\n");
    printf("         ■■■■■■      ■            ■   ■■■■■■■   ■■■■■■■   ■■■■■■      ■            ■   ■■■■■■■   ■■■■■■■          ■   ■   ■       ■■■\n");

    printf("\n\n\n============================숫자야구 규칙=======================예시)   정답  \t숫자\t정보\n\n");
    printf("1. 숫자야구는 컴퓨터가 제시하는 네 자리 숫자를 맞추는 게임입니다.     \t1027  \t1028\t3S0B\n\n");
    printf("2. 사용되는 숫자는 0부터 9까지이며, 각 자리의 숫자는 모두 다릅니다.   \t      \t0142\t0S3B\n\n");
    printf("3. 숫자는 일치하지만 위치가 틀렸을 때는 ball입니다.                  \t      \t3456\t OUT\n\n");
    printf("4. 숫자와 위치가 둘 다 일치하면 strike입니다.                       \t      \t1872\t1S2B\n\n");
    printf("5. 숫자가 4개 모두 일치하지 않으면 OUT입니다.                       \t      \t9999\t3번째 숫자는 0입니다.\n\n");
    printf("6. 정답을 맞출 수 있는 기회는 25~10번입니다.\n\n");
    printf("7. 딱 1번, 남은 기회가 10회 이하일 경우 9999를 입력하여 힌트를 사용할 수 있습니다. \n\n");
    printf("   힌트를 사용하면 무작위로 한 자리의 숫자를 알려줍니다. 단, 남은 기회가 3회 줄어듭니다. \n\n");
    printf("   또한 어려움 난이도에서는 힌트를 사용할 수 없습니다. \n\n");
    printf("======================================================================\n\n\n\n");
    printf("게임을 시작하려면 Enter키를 누르세요.");

    enter = getc(stdin);    // 입력된 문자를 enter변수에 저장

    if (enter == '\n')      // 엔터 키 입력 시 화면지우고 return
        system("cls");

    return;                 
}

int selectDifficulty()      // 난이도를 입력받아 count를 반환하는 함수
{
    int count = 0;
    char difficulty = '\0';

    printf("난이도를 골라주세요.\n\n");
    printf("입력에 따라 정답을 맞출 수 있는 횟수가 달라집니다.\n\n");
    printf("1. 입문    2. 쉬움    3. 보통    4. 어려움\n\n");

    scanf("%c", &difficulty);

    switch (difficulty)
    {
    case '1':
        printf("입문 난이도를 선택하셨습니다.\n");
        count = 25;
        break;
    case '2':
        printf("쉬움 난이도를 선택하셨습니다.\n");
        count = 20;
        break;
    case '3':
        printf("보통 난이도를 선택하셨습니다.\n");
        count = 15;
        break;
    case '4':
        printf("어려움 난이도를 선택하셨습니다.\n");
        count = 10;
        hint_count = 0;
        break;
    default:
        count = 15;
        printf("잘못된 입력입니다.\n");
        printf("보통 난이도로 진행합니다.\n");
    }

    return count;
}

int* getComputerNumber()    // 무작위로 네 자리 정답을 생성하는 함수
{
    int temp = 0; // 같은 숫자가 생성됐는지 검사

    srand((unsigned)time(NULL));
    // 실행할 때마다 다른 무작위 수가 나오게 하기 위함.
    // windows 시간 기준으로 추출한다. (time.h)

    for (i = 0; i < SIZE; i++) // answer[0]~[3]까지 하나씩 난수 생성
    {
        temp = rand() % 10;
        answer[i] = temp;

        for (j = 0; j < i; j++)      // answer[0]~[i-1] 중에
            if ((temp == answer[j])) // answer[i]와 같은 숫자가 있으면
                i--;                 // answer[i] 다시 생성
    }

    // answer가 제대로 생성되었는지 확인 
    // for (i = 0; i < SIZE; i++) printf("%d", answer[i]);

    return answer;
}

int* getPlayerNumber(int* count) // 플레이어의 네 자리 숫자를 입력받는 함수
{
    int temp = 0; // 네 자리 수를 쪼갤 temp

    while (1) // 올바른 수가 입력될 때까지 무한반복
    {
        printf("\n\n남은 기회: %d회\n네 자리 수를 입력하세요: ", *count);
        scanf("%d", &playerNumber);

        if (playerNumber == 9999) // 힌트를 사용하려고 9999를 입력했을 시
        {
            if (hint_count == 0)
            {
                printf("힌트를 이미 사용하셨습니다.\n");
                continue;

            }
            else if (*count > 10 || *count < 4)
            {
                printf("힌트는 남은 기회가 4회 이상 10회 이하일 때 사용할 수 있습니다.\n");
                continue;
            }
            else
                return 0;
        }

        if (playerNumber > 9999) // 다섯자리 이상의 수를 입력했을 때
        {
            printf("잘못된 수를 입력했습니다. 다시 입력하세요.\n");
            continue;
        }

        temp = playerNumber;

        playerAnswer[0] = playerNumber / 1000; // 천의 자리: 첫번째 숫자
        temp %= 1000;

        playerAnswer[1] = temp / 100; // 백의 자리: 두번째 숫자
        temp %= 100;

        if (playerAnswer[1] == playerAnswer[0]) // 첫번째가 두번째와 같은지 검사
        {
            printf("잘못된 수를 입력했습니다. 다시 입력하세요.\n");
            continue;
        }

        playerAnswer[2] = temp / 10; // 십의 자리: 세번째 숫자
        temp %= 10;

        // 첫번째 또는 두번째가 세번째와 같은지 검사
        if (playerAnswer[2] == playerAnswer[0] || playerAnswer[2] == playerAnswer[1])
        {
            printf("잘못된 수를 입력했습니다. 다시 입력하세요.\n");
            continue;
        }

        playerAnswer[3] = temp; // 일의 자리: 4번째 숫자

        // 첫번째 또는 두번째 또는 세번째가 네번째와 같은지 검사
        if (playerAnswer[3] == playerAnswer[0] || playerAnswer[3] == playerAnswer[1] || playerAnswer[3] == playerAnswer[2])
        {
            printf("잘못된 수를 입력했습니다. 다시 입력하세요.\n");
            continue;
        }

        break;
    }

    return playerAnswer;
}

int checkAnswer() // 정답 여부를 검사하는 함수
{
    if (playerNumber == 9999) // 9999를 입력했을 시에는 정답검사x
        return 0;

    for (i = 0; i < SIZE; i++)  // 1~4번째까지 다른 숫자가 있으면 0 반환
    {
        if (answer[i] != playerAnswer[i])
            return 0;
    }

    return 1; // 모두 같으면 1 반환
}

void printHint(char* hint)      // 스트라이크, 볼 정보를 출력하는 함수
{
    int strike = 0, ball = 0;   // 스트라이크, 볼 정보를 저장할 변수
    char temphint[40];        // 힌트를 누적하기 위한 문자열

    if (hint_count > 0 && playerNumber == 9999)
        return;                 // 9999를 입력했을 시에는 출력x

    for (i = 0; i < SIZE; i++)      // 정답의 1~4번째 숫자 탑색
        for (j = 0; j < SIZE; j++)  // 입력한 수의 1~4번째 숫자 탐색
            if (answer[i] == playerAnswer[j])   // 같은 숫자가 있을 경우
                if (i == j)         // 숫자의 위치도 같을 경우
                    strike++;
                else                // 위치는 다를 경우
                    ball++;

    sprintf(temphint, "%d%d%d%-8d\t%-5d\t%-3d\n", playerAnswer[0], playerAnswer[1], playerAnswer[2], playerAnswer[3], strike, ball);
    // 스트라이크, 볼 정보를 저장한 문자열을 temphint에 저장
    // 원래 strcpy를 사용하려 했지만 %d때문에 안됨 (string.h)

    if (strike == 0 && ball == 0) // strike와 ball이 0이면 OUT
        sprintf(temphint, "%d%d%d%d  (OUT)\t%d\t%-3d\n", playerAnswer[0], playerAnswer[1], playerAnswer[2], playerAnswer[3], strike, ball);

    hint = strcat(hint, temphint); // temphint를 hint에 붙이기

    printf("%s", hint);            // 누적된 정보 문자열 hint 출력

    return;
}

void get_hint(char* hint)   // 힌트를 출력하는 함수 
{
    int random_index = 0;   // 몇 번째 숫자를 공개할 지 랜덤으로 정할 변수
    char getHint[40];       // 힌트를 누적하기 위한 문자열

    random_index = rand() % 4; // 0~3 랜덤으로 저장

    sprintf(getHint, "☆☆%d번째 숫자는 %d입니다.☆☆\n", random_index + 1, answer[random_index]);
    // 임시 문자열에 힌트 저장

    hint = strcat(hint, getHint);   // 임시 문자열을 hint에 붙이기

    printf("%s", hint); // 누적된 문자열 hint 출력

    hint_count--; // 힌트를 사용했으므로 0으로 만들어주기

    return;
}

int main()
{
    char hint[1024] = "\n입력한 숫자\tSTRIKE\tBALL\n";
    int count = 0;  // 남은 기회
    int check = 0;  // 정답, 오답 여부 
    int chance = 0; // 정답을 입력한 횟수 

    printTutorial();
    count = selectDifficulty();

    Sleep(2000);    // 2초 후에 실행 (windows.h)

    printf("\n숫자야구 게임을 시작합니다.\n");

    Sleep(1500);
    system("cls"); // 화면 지우기 (windows.h)


    for (i = 0; i < 3; i++)
    {
        printf("컴퓨터가 숫자를 생각하는중.");
        Sleep(500);
        system("cls");
        printf("컴퓨터가 숫자를 생각하는중..");
        Sleep(500);
        system("cls");
        printf("컴퓨터가 숫자를 생각하는중...");
        Sleep(500);
        system("cls");
    }

    printf("컴퓨터가 생각을 마쳤습니다.");

    int* answer = getComputerNumber();

    do
    {
        int* playerAnswer = getPlayerNumber(&count);
        check = checkAnswer();
        count--;    // 기회 1 감소
        chance++;   // 입력횟수 1 증가
        system("cls");
        printHint(hint);

        if (playerNumber == 9999) // 9999 입력
        {
            get_hint(hint);
            chance--;   // 입력횟수 1 감소
            count -= 2; // 기회 추가로 2 감소
        }

    } while (check == 0 && count != 0); // 오답을 입력하거나 기회가 남아있으면 반복

    if (check)  // 정답을 입력한 경우
    {
        printf("축하합니다! %d번만에 정답을 맞추었습니다!\n\n\n", chance);
        printf("  ■          ■    ■■■■■■■   ■          ■\n");
        printf("    ■      ■      ■          ■   ■          ■\n");
        printf("      ■  ■        ■          ■   ■          ■\n");
        printf("        ■          ■          ■   ■          ■\n");
        printf("        ■          ■          ■   ■          ■\n");
        printf("        ■          ■          ■   ■          ■\n");
        printf("        ■          ■■■■■■■   ■■■■■■■\n");
        printf("\n\n");
        printf("■     ■      ■     ■■■■■      ■          ■\n");
        printf("■     ■      ■         ■          ■■        ■\n");
        printf("■     ■      ■         ■          ■  ■      ■\n");
        printf(" ■    ■     ■          ■          ■    ■    ■\n");
        printf("  ■  ■ ■  ■           ■          ■      ■  ■\n");
        printf("   ■ ■ ■ ■            ■          ■        ■■\n");
        printf("     ■    ■         ■■■■■      ■          ■\n");
    }

    else
    {// 정답을 맞추지 못한 채 입력 횟수를 모두 쓴 경우
        printf("\n정답은 %d%d%d%d이었습니다.\n\n\n", answer[0], answer[1], answer[2], answer[3]);
        printf("         ■          ■    ■■■■■■■   ■          ■\n");
        printf("           ■      ■      ■          ■   ■          ■\n");
        printf("             ■  ■        ■          ■   ■          ■\n");
        printf("               ■          ■          ■   ■          ■\n");
        printf("               ■          ■          ■   ■          ■\n");
        printf("               ■          ■          ■   ■          ■\n");
        printf("               ■          ■■■■■■■   ■■■■■■■\n");
        printf("\n\n");
        printf("■                ■■■■■■■    ■■■■■■■    ■■■■■■■\n");
        printf("■                ■          ■    ■                ■\n");
        printf("■                ■          ■    ■                ■\n");
        printf("■                ■          ■    ■■■■■■■    ■■■■■■■\n");
        printf("■                ■          ■                ■    ■\n");
        printf("■                ■          ■                ■    ■\n");
        printf("■■■■■■■    ■■■■■■■    ■■■■■■■    ■■■■■■■\n");
    }

    return 0;
}
