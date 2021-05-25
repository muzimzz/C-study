#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define SIZE 4  // ������ �� �ڸ� ��

int i = 0, j = 0;               // for���� ���� ����
int hint_count = 1;             // ��Ʈ ��� ����
int playerNumber = 0;           // ����ڰ� �Է��� �� �ڸ� ��
int playerAnswer[SIZE] = { 0 }; // �Է��� �� �ڸ� ���� �ɰ� �迭�� ����
int answer[SIZE] = { 0 };       // ��ǻ�Ͱ� ������ ���� �迭

void printTutorial() // ��Ģ�� ����ϴ� �Լ�
{
    char enter;

    printf("                        ��          ��   ��            ��   ��            ��   �������      ��������   ������\n");
    printf("                        ���        ��   ��            ��   ���        ���   ��          ��    ��               ��        ��\n");
    printf("                        ��  ��      ��   ��            ��   ��  ��    ��  ��   ��          ��    ��               ��        ��\n");
    printf("                        ��    ��    ��   ��            ��   ��     ��     ��   �������      ��������   ��������\n");
    printf("                        ��      ��  ��   ��            ��   ��            ��   ��          ��    ��               ��           ��\n");
    printf("                        ��        ���   ��            ��   ��            ��   ��          ��    ��               ��           ��\n");
    printf("                        ��          ��   ���������   ��            ��   �������      ��������   ��           ��\n");
    printf("\n\n");
    printf("         �������             ��          ��������   ��������   �������             ��          ��               ��\n");
    printf("         ��          ��         ��  ��        ��               ��               ��          ��         ��  ��        ��               ��\n");
    printf("         ��          ��       ��      ��      ��               ��               ��          ��       ��      ��      ��               ��                      ��   ��   ����   ����\n");
    printf("         �������        �������     ��������   ��������   �������        �������     ��               ��                      ��  ��    ��   ��  ��\n");
    printf("         ��          ��     ��          ��                ��   ��               ��          ��     ��          ��    ��               ��                      ���      ����   ��\n");
    printf("         ��          ��    ��            ��               ��   ��               ��          ��    ��            ��   ��               ��                      ��  ��    ��       ��\n");
    printf("         �������      ��            ��   ��������   ��������   �������      ��            ��   ��������   ��������          ��   ��   ��       ����\n");

    printf("\n\n\n============================���ھ߱� ��Ģ=======================����)   ����  \t����\t����\n\n");
    printf("1. ���ھ߱��� ��ǻ�Ͱ� �����ϴ� �� �ڸ� ���ڸ� ���ߴ� �����Դϴ�.     \t1027  \t1028\t3S0B\n\n");
    printf("2. ���Ǵ� ���ڴ� 0���� 9�����̸�, �� �ڸ��� ���ڴ� ��� �ٸ��ϴ�.   \t      \t0142\t0S3B\n\n");
    printf("3. ���ڴ� ��ġ������ ��ġ�� Ʋ���� ���� ball�Դϴ�.                  \t      \t3456\t OUT\n\n");
    printf("4. ���ڿ� ��ġ�� �� �� ��ġ�ϸ� strike�Դϴ�.                       \t      \t1872\t1S2B\n\n");
    printf("5. ���ڰ� 4�� ��� ��ġ���� ������ OUT�Դϴ�.                       \t      \t9999\t3��° ���ڴ� 0�Դϴ�.\n\n");
    printf("6. ������ ���� �� �ִ� ��ȸ�� 25~10���Դϴ�.\n\n");
    printf("7. �� 1��, ���� ��ȸ�� 10ȸ ������ ��� 9999�� �Է��Ͽ� ��Ʈ�� ����� �� �ֽ��ϴ�. \n\n");
    printf("   ��Ʈ�� ����ϸ� �������� �� �ڸ��� ���ڸ� �˷��ݴϴ�. ��, ���� ��ȸ�� 3ȸ �پ��ϴ�. \n\n");
    printf("   ���� ����� ���̵������� ��Ʈ�� ����� �� �����ϴ�. \n\n");
    printf("======================================================================\n\n\n\n");
    printf("������ �����Ϸ��� EnterŰ�� ��������.");

    enter = getc(stdin);    // �Էµ� ���ڸ� enter������ ����

    if (enter == '\n')      // ���� Ű �Է� �� ȭ������� return
        system("cls");

    return;                 
}

int selectDifficulty()      // ���̵��� �Է¹޾� count�� ��ȯ�ϴ� �Լ�
{
    int count = 0;
    char difficulty = '\0';

    printf("���̵��� ����ּ���.\n\n");
    printf("�Է¿� ���� ������ ���� �� �ִ� Ƚ���� �޶����ϴ�.\n\n");
    printf("1. �Թ�    2. ����    3. ����    4. �����\n\n");

    scanf("%c", &difficulty);

    switch (difficulty)
    {
    case '1':
        printf("�Թ� ���̵��� �����ϼ̽��ϴ�.\n");
        count = 25;
        break;
    case '2':
        printf("���� ���̵��� �����ϼ̽��ϴ�.\n");
        count = 20;
        break;
    case '3':
        printf("���� ���̵��� �����ϼ̽��ϴ�.\n");
        count = 15;
        break;
    case '4':
        printf("����� ���̵��� �����ϼ̽��ϴ�.\n");
        count = 10;
        hint_count = 0;
        break;
    default:
        count = 15;
        printf("�߸��� �Է��Դϴ�.\n");
        printf("���� ���̵��� �����մϴ�.\n");
    }

    return count;
}

int* getComputerNumber()    // �������� �� �ڸ� ������ �����ϴ� �Լ�
{
    int temp = 0; // ���� ���ڰ� �����ƴ��� �˻�

    srand((unsigned)time(NULL));
    // ������ ������ �ٸ� ������ ���� ������ �ϱ� ����.
    // windows �ð� �������� �����Ѵ�. (time.h)

    for (i = 0; i < SIZE; i++) // answer[0]~[3]���� �ϳ��� ���� ����
    {
        temp = rand() % 10;
        answer[i] = temp;

        for (j = 0; j < i; j++)      // answer[0]~[i-1] �߿�
            if ((temp == answer[j])) // answer[i]�� ���� ���ڰ� ������
                i--;                 // answer[i] �ٽ� ����
    }

    // answer�� ����� �����Ǿ����� Ȯ�� 
    // for (i = 0; i < SIZE; i++) printf("%d", answer[i]);

    return answer;
}

int* getPlayerNumber(int* count) // �÷��̾��� �� �ڸ� ���ڸ� �Է¹޴� �Լ�
{
    int temp = 0; // �� �ڸ� ���� �ɰ� temp

    while (1) // �ùٸ� ���� �Էµ� ������ ���ѹݺ�
    {
        printf("\n\n���� ��ȸ: %dȸ\n�� �ڸ� ���� �Է��ϼ���: ", *count);
        scanf("%d", &playerNumber);

        if (playerNumber == 9999) // ��Ʈ�� ����Ϸ��� 9999�� �Է����� ��
        {
            if (hint_count == 0)
            {
                printf("��Ʈ�� �̹� ����ϼ̽��ϴ�.\n");
                continue;

            }
            else if (*count > 10 || *count < 4)
            {
                printf("��Ʈ�� ���� ��ȸ�� 4ȸ �̻� 10ȸ ������ �� ����� �� �ֽ��ϴ�.\n");
                continue;
            }
            else
                return 0;
        }

        if (playerNumber > 9999) // �ټ��ڸ� �̻��� ���� �Է����� ��
        {
            printf("�߸��� ���� �Է��߽��ϴ�. �ٽ� �Է��ϼ���.\n");
            continue;
        }

        temp = playerNumber;

        playerAnswer[0] = playerNumber / 1000; // õ�� �ڸ�: ù��° ����
        temp %= 1000;

        playerAnswer[1] = temp / 100; // ���� �ڸ�: �ι�° ����
        temp %= 100;

        if (playerAnswer[1] == playerAnswer[0]) // ù��°�� �ι�°�� ������ �˻�
        {
            printf("�߸��� ���� �Է��߽��ϴ�. �ٽ� �Է��ϼ���.\n");
            continue;
        }

        playerAnswer[2] = temp / 10; // ���� �ڸ�: ����° ����
        temp %= 10;

        // ù��° �Ǵ� �ι�°�� ����°�� ������ �˻�
        if (playerAnswer[2] == playerAnswer[0] || playerAnswer[2] == playerAnswer[1])
        {
            printf("�߸��� ���� �Է��߽��ϴ�. �ٽ� �Է��ϼ���.\n");
            continue;
        }

        playerAnswer[3] = temp; // ���� �ڸ�: 4��° ����

        // ù��° �Ǵ� �ι�° �Ǵ� ����°�� �׹�°�� ������ �˻�
        if (playerAnswer[3] == playerAnswer[0] || playerAnswer[3] == playerAnswer[1] || playerAnswer[3] == playerAnswer[2])
        {
            printf("�߸��� ���� �Է��߽��ϴ�. �ٽ� �Է��ϼ���.\n");
            continue;
        }

        break;
    }

    return playerAnswer;
}

int checkAnswer() // ���� ���θ� �˻��ϴ� �Լ�
{
    if (playerNumber == 9999) // 9999�� �Է����� �ÿ��� ����˻�x
        return 0;

    for (i = 0; i < SIZE; i++)  // 1~4��°���� �ٸ� ���ڰ� ������ 0 ��ȯ
    {
        if (answer[i] != playerAnswer[i])
            return 0;
    }

    return 1; // ��� ������ 1 ��ȯ
}

void printHint(char* hint)      // ��Ʈ����ũ, �� ������ ����ϴ� �Լ�
{
    int strike = 0, ball = 0;   // ��Ʈ����ũ, �� ������ ������ ����
    char temphint[40];        // ��Ʈ�� �����ϱ� ���� ���ڿ�

    if (hint_count > 0 && playerNumber == 9999)
        return;                 // 9999�� �Է����� �ÿ��� ���x

    for (i = 0; i < SIZE; i++)      // ������ 1~4��° ���� ž��
        for (j = 0; j < SIZE; j++)  // �Է��� ���� 1~4��° ���� Ž��
            if (answer[i] == playerAnswer[j])   // ���� ���ڰ� ���� ���
                if (i == j)         // ������ ��ġ�� ���� ���
                    strike++;
                else                // ��ġ�� �ٸ� ���
                    ball++;

    sprintf(temphint, "%d%d%d%-8d\t%-5d\t%-3d\n", playerAnswer[0], playerAnswer[1], playerAnswer[2], playerAnswer[3], strike, ball);
    // ��Ʈ����ũ, �� ������ ������ ���ڿ��� temphint�� ����
    // ���� strcpy�� ����Ϸ� ������ %d������ �ȵ� (string.h)

    if (strike == 0 && ball == 0) // strike�� ball�� 0�̸� OUT
        sprintf(temphint, "%d%d%d%d  (OUT)\t%d\t%-3d\n", playerAnswer[0], playerAnswer[1], playerAnswer[2], playerAnswer[3], strike, ball);

    hint = strcat(hint, temphint); // temphint�� hint�� ���̱�

    printf("%s", hint);            // ������ ���� ���ڿ� hint ���

    return;
}

void get_hint(char* hint)   // ��Ʈ�� ����ϴ� �Լ� 
{
    int random_index = 0;   // �� ��° ���ڸ� ������ �� �������� ���� ����
    char getHint[40];       // ��Ʈ�� �����ϱ� ���� ���ڿ�

    random_index = rand() % 4; // 0~3 �������� ����

    sprintf(getHint, "�١�%d��° ���ڴ� %d�Դϴ�.�١�\n", random_index + 1, answer[random_index]);
    // �ӽ� ���ڿ��� ��Ʈ ����

    hint = strcat(hint, getHint);   // �ӽ� ���ڿ��� hint�� ���̱�

    printf("%s", hint); // ������ ���ڿ� hint ���

    hint_count--; // ��Ʈ�� ��������Ƿ� 0���� ������ֱ�

    return;
}

int main()
{
    char hint[1024] = "\n�Է��� ����\tSTRIKE\tBALL\n";
    int count = 0;  // ���� ��ȸ
    int check = 0;  // ����, ���� ���� 
    int chance = 0; // ������ �Է��� Ƚ�� 

    printTutorial();
    count = selectDifficulty();

    Sleep(2000);    // 2�� �Ŀ� ���� (windows.h)

    printf("\n���ھ߱� ������ �����մϴ�.\n");

    Sleep(1500);
    system("cls"); // ȭ�� ����� (windows.h)


    for (i = 0; i < 3; i++)
    {
        printf("��ǻ�Ͱ� ���ڸ� �����ϴ���.");
        Sleep(500);
        system("cls");
        printf("��ǻ�Ͱ� ���ڸ� �����ϴ���..");
        Sleep(500);
        system("cls");
        printf("��ǻ�Ͱ� ���ڸ� �����ϴ���...");
        Sleep(500);
        system("cls");
    }

    printf("��ǻ�Ͱ� ������ ���ƽ��ϴ�.");

    int* answer = getComputerNumber();

    do
    {
        int* playerAnswer = getPlayerNumber(&count);
        check = checkAnswer();
        count--;    // ��ȸ 1 ����
        chance++;   // �Է�Ƚ�� 1 ����
        system("cls");
        printHint(hint);

        if (playerNumber == 9999) // 9999 �Է�
        {
            get_hint(hint);
            chance--;   // �Է�Ƚ�� 1 ����
            count -= 2; // ��ȸ �߰��� 2 ����
        }

    } while (check == 0 && count != 0); // ������ �Է��ϰų� ��ȸ�� ���������� �ݺ�

    if (check)  // ������ �Է��� ���
    {
        printf("�����մϴ�! %d������ ������ ���߾����ϴ�!\n\n\n", chance);
        printf("  ��          ��    ��������   ��          ��\n");
        printf("    ��      ��      ��          ��   ��          ��\n");
        printf("      ��  ��        ��          ��   ��          ��\n");
        printf("        ��          ��          ��   ��          ��\n");
        printf("        ��          ��          ��   ��          ��\n");
        printf("        ��          ��          ��   ��          ��\n");
        printf("        ��          ��������   ��������\n");
        printf("\n\n");
        printf("��     ��      ��     ������      ��          ��\n");
        printf("��     ��      ��         ��          ���        ��\n");
        printf("��     ��      ��         ��          ��  ��      ��\n");
        printf(" ��    ��     ��          ��          ��    ��    ��\n");
        printf("  ��  �� ��  ��           ��          ��      ��  ��\n");
        printf("   �� �� �� ��            ��          ��        ���\n");
        printf("     ��    ��         ������      ��          ��\n");
    }

    else
    {// ������ ������ ���� ä �Է� Ƚ���� ��� �� ���
        printf("\n������ %d%d%d%d�̾����ϴ�.\n\n\n", answer[0], answer[1], answer[2], answer[3]);
        printf("         ��          ��    ��������   ��          ��\n");
        printf("           ��      ��      ��          ��   ��          ��\n");
        printf("             ��  ��        ��          ��   ��          ��\n");
        printf("               ��          ��          ��   ��          ��\n");
        printf("               ��          ��          ��   ��          ��\n");
        printf("               ��          ��          ��   ��          ��\n");
        printf("               ��          ��������   ��������\n");
        printf("\n\n");
        printf("��                ��������    ��������    ��������\n");
        printf("��                ��          ��    ��                ��\n");
        printf("��                ��          ��    ��                ��\n");
        printf("��                ��          ��    ��������    ��������\n");
        printf("��                ��          ��                ��    ��\n");
        printf("��                ��          ��                ��    ��\n");
        printf("��������    ��������    ��������    ��������\n");
    }

    return 0;
}
