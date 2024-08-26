#define _CRT_SECURE_NO_WARNINGS
#define remainChance(chanceNo) chanceNo - 1 /*rule20.07*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> /*rule 21.10*/
#include <stdbool.h>


int grade; /* rule 08.06 */
char error;
char* gamerNumPtr;

/************************************************** ���ٿ���� ���� **************************************************/
/*���ٿ���� �Լ�*/
#define defgamerNameIngame 1
int defgamerNameIngame_f()
{
    int gamerNameIngame = 0;
#ifndef defgamerNameIngame
    gamerNameIngame = 1;
    #else1 /*rule 20.13: �νĵ��� ���� #*/
        x = defgamerNameIngame;
#endif
}

void userredo();
int udgame();

// Data {/*rule 19.02: union Ÿ���� ���Ǹ� �ȵ�*/
//    int errarr;
//    double errarrerr[];
//}str;

union Data { /*rule 19.02: union Ÿ���� ���Ǹ� �ȵ�*/
    int errarr;
    double errarrerr;
};

struct DataWrapper {
    union Data data;
    int type[];/*rule 18.07: type�� �����迭�� ����Ǿ���*/
}data;

void unionFn(void) {
    union Data a = { .errarrerr = 0 };
    a.errarr = 0;
    a.errarrerr = 1;
    a.errarr = (int)a.errarrerr; /*rule 19.01: union ���� a �� �ٸ� Ÿ���� ��� �� �Ҵ�Ǹ� �ȵ�*/
    printf("����� ID: %d\n\n", a.errarr);
}

void userredo()
{
    char again = ' ';
    int start_val = 0;

    /*NOT����*/
    while (!start_val) { // rule 10.01
        printf("��� �Ͻðڽ��ϱ�? (y/n)\n");
        scanf(" %c", &again);
        printf("\n");

        /*OR����*/
        if (again == 'n' || again == 'N') {
            printf("������ �����մϴ�\n");
            main();
        }
        else if (again == 'y' || again == 'Y') {
            printf("������ �ٽ� �����մϴ�.\n");
            udgame(1);
            start_val = 1;
        }
        else {
            printf("�߸��� �Է��Դϴ�.\n");
            while (getchar() != '\n'); /*�Է¹��� ���*/
        }
    }
}


int udgame() /*rule 17.02*/
{
    srand(time(NULL));

#if gamer/*rule 20.09: gamer��ũ�ΰ� ����Ǿ� ���� ����*/ 
#define USERMESSAGE "Welcome Gamer\n"
#else
#define USERMESSAGE "==���ٿ� ������ �����մϴ�=="
#endif
    printf("%s\n", USERMESSAGE);
    int gamerNameIngame = 1;
    gamerNumPtr = &gamerNameIngame; /*rule 18.06: ���������� �ּҰ� �ڽ��� scope�� �Ѿ�� ������ �Ҵ��*/
    printf("���̸� �̸�: %d\n", *gamerNumPtr);
    unionFn();

    int num = rand() % 100 + 1; /*1 ~ 100 ��ȯ*/
    printf("������ %d\n\n", num);

    const char* preAnswer = "0";
    int answer = atol(preAnswer); /*rule 21.07: atol�� ����� ������ �Լ���*/
    int chance[1] = { 5 };
    /*int chance[chancesize]; rule 18.08 */
    int chanceMinOne[1] = { 5 };

    int* chancePtr = &chance[0];
    chancePtr -= 1; /*rule 18.04: ���������� ���Ŀ� -= �����ڰ� ����*/
    int* chanceMinOnePtr = &chanceMinOne[0];
    int** chancePtr2 = &chancePtr;
    int*** chancePtr3 = &chancePtr2; /*rule 18.05: 3�� �����͸� ������*/
    if (chancePtr > chanceMinOnePtr) { /*rule 18.03: ���� ��ü�� ����Ű�� �ʴ� �����ͳ����� �񱳿����� ����*/
        printf("��Ģ���� ������ �����մϴ�.\n\n");
    }

    int chanceNo = /*chancePtr*/remainChance(chancePtr - 1) - chanceMinOnePtr + 5; /*rule 18.02: �ٸ� �迭�� ��ҿ� ���� ������ ���������� ����, rule 20.07: chancePtr -1�� ��ȣ�� ���ο����� ����*/

    while (chanceNo > 0) /*rule 15.04: �ݺ����� jump ���� 5 �� ���Ǿ���*/
    {
        printf("������ȸ: %d\n", chanceNo--); // rule 13.03
        printf("���ڸ� ���纸����. (1~100)\n");
        printf("\n");

        /*OR����*/
        if ((scanf("%d", &answer) != 1) || (answer < 1 || answer > 100)) {
            printf("�߸��� �Է��Դϴ�. �ùٸ� ������ ���ڸ� �Է����ּ���.\n");
            while (getchar() != '\n');
            chanceNo++; /*��ȸ ���� ����*/
            continue;
        }

        /*���� �� ���ӷ��� �б�*/
            /*AND����*/
        if (answer == num && chanceNo == 0) {
            printf("�ƽ��ƽ��ϰ� ����!\n\n");
            userredo();
            break;
        }
        else if (answer == num) {
            printf("����!\n\n");
            userredo();
            break;
        }
        else if (chanceNo == 0) {
        fail2:
            printf("���� ");
            goto fail; /* Rule 15.01: goto ���� ��� ����, Rule 15.03: goto���� �����ϴ� ���̺��� ���� ��Ͽ��� ����Ǿ����� ����*/
            free(chancePtr); /*rule 21.03: free�� ����� ������ �Լ���*/
            goto fail2; //rule 15.02: goto ���� label ������ goto ������ ���߿� �־�� ��

            printf("�� �ڵ�� �۵����� ���� !\n");

            userredo();
            break;
            printf("������ �� ���� �ڵ� 0201"); /*Rule 02.01*/
        }
        else if (answer > num) {
            printf("��down��\n\n");
        }
        else if (answer < num) {
            printf("��up��\n\n");
        }
        /*rule 15.07: else if ���� else�� ����*/
    }
fail:
    {
        printf("%s\n", /*textMerge*/ "�Ͽ����ϴ�");
        userredo();
        free(chancePtr); /*rule 21.03, rule 22.02: �ߺ� free�� ��*/
    }

} /*rule 17.04: int�� �Լ��ε� return���� ����*/