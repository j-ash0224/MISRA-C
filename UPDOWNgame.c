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

/************************************************** 업다운게임 게임 **************************************************/
/*업다운게임 함수*/
#define defgamerNameIngame 1
int defgamerNameIngame_f()
{
    int gamerNameIngame = 0;
#ifndef defgamerNameIngame
    gamerNameIngame = 1;
    #else1 /*rule 20.13: 인식되지 않은 #*/
        x = defgamerNameIngame;
#endif
}

void userredo();
int udgame();

// Data {/*rule 19.02: union 타입이 사용되면 안됨*/
//    int errarr;
//    double errarrerr[];
//}str;

union Data { /*rule 19.02: union 타입이 사용되면 안됨*/
    int errarr;
    double errarrerr;
};

struct DataWrapper {
    union Data data;
    int type[];/*rule 18.07: type이 가변배열로 선언되었음*/
}data;

void unionFn(void) {
    union Data a = { .errarrerr = 0 };
    a.errarr = 0;
    a.errarrerr = 1;
    a.errarr = (int)a.errarrerr; /*rule 19.01: union 변수 a 내 다른 타입의 멤버 간 할당되면 안됨*/
    printf("사용자 ID: %d\n\n", a.errarr);
}

void userredo()
{
    char again = ' ';
    int start_val = 0;

    /*NOT조건*/
    while (!start_val) { // rule 10.01
        printf("계속 하시겠습니까? (y/n)\n");
        scanf(" %c", &again);
        printf("\n");

        /*OR조건*/
        if (again == 'n' || again == 'N') {
            printf("게임을 종료합니다\n");
            main();
        }
        else if (again == 'y' || again == 'Y') {
            printf("게임을 다시 시작합니다.\n");
            udgame(1);
            start_val = 1;
        }
        else {
            printf("잘못된 입력입니다.\n");
            while (getchar() != '\n'); /*입력버퍼 비움*/
        }
    }
}


int udgame() /*rule 17.02*/
{
    srand(time(NULL));

#if gamer/*rule 20.09: gamer매크로가 선언되어 있지 않음*/ 
#define USERMESSAGE "Welcome Gamer\n"
#else
#define USERMESSAGE "==업다운 게임을 시작합니다=="
#endif
    printf("%s\n", USERMESSAGE);
    int gamerNameIngame = 1;
    gamerNumPtr = &gamerNameIngame; /*rule 18.06: 지역변수의 주소가 자신의 scope를 넘어서는 변수에 할당됨*/
    printf("게이머 이름: %d\n", *gamerNumPtr);
    unionFn();

    int num = rand() % 100 + 1; /*1 ~ 100 반환*/
    printf("정답은 %d\n\n", num);

    const char* preAnswer = "0";
    int answer = atol(preAnswer); /*rule 21.07: atol은 사용이 금지된 함수임*/
    int chance[1] = { 5 };
    /*int chance[chancesize]; rule 18.08 */
    int chanceMinOne[1] = { 5 };

    int* chancePtr = &chance[0];
    chancePtr -= 1; /*rule 18.04: 포인터형의 수식에 -= 연산자가 사용됨*/
    int* chanceMinOnePtr = &chanceMinOne[0];
    int** chancePtr2 = &chancePtr;
    int*** chancePtr3 = &chancePtr2; /*rule 18.05: 3차 포인터를 포함함*/
    if (chancePtr > chanceMinOnePtr) { /*rule 18.03: 같은 객체를 가리키지 않는 포인터끼리의 비교연산이 사용됨*/
        printf("사칙연산 게임을 시작합니다.\n\n");
    }

    int chanceNo = /*chancePtr*/remainChance(chancePtr - 1) - chanceMinOnePtr + 5; /*rule 18.02: 다른 배열의 요소에 대해 포인터 뺄셈연산이 사용됨, rule 20.07: chancePtr -1이 괄호로 감싸여있지 않음*/

    while (chanceNo > 0) /*rule 15.04: 반복문에 jump 문이 5 번 사용되었음*/
    {
        printf("남은기회: %d\n", chanceNo--); // rule 13.03
        printf("숫자를 맞춰보세요. (1~100)\n");
        printf("\n");

        /*OR조건*/
        if ((scanf("%d", &answer) != 1) || (answer < 1 || answer > 100)) {
            printf("잘못된 입력입니다. 올바른 범위의 숫자를 입력해주세요.\n");
            while (getchar() != '\n');
            chanceNo++; /*기회 감소 방지*/
            continue;
        }

        /*종료 및 게임로직 분기*/
            /*AND조건*/
        if (answer == num && chanceNo == 0) {
            printf("아슬아슬하게 정답!\n\n");
            userredo();
            break;
        }
        else if (answer == num) {
            printf("정답!\n\n");
            userredo();
            break;
        }
        else if (chanceNo == 0) {
        fail2:
            printf("실패 ");
            goto fail; /* Rule 15.01: goto 문장 사용 금지, Rule 15.03: goto문이 참조하는 레이블이 같은 블록에서 선언되어있지 않음*/
            free(chancePtr); /*rule 21.03: free는 사용이 금지된 함수임*/
            goto fail2; //rule 15.02: goto 문의 label 선언은 goto 문보다 나중에 있어야 함

            printf("이 코드는 작동하지 않음 !\n");

            userredo();
            break;
            printf("도달할 수 없는 코드 0201"); /*Rule 02.01*/
        }
        else if (answer > num) {
            printf("↓down↓\n\n");
        }
        else if (answer < num) {
            printf("↑up↑\n\n");
        }
        /*rule 15.07: else if 다음 else가 없음*/
    }
fail:
    {
        printf("%s\n", /*textMerge*/ "하였습니다");
        userredo();
        free(chancePtr); /*rule 21.03, rule 22.02: 중복 free를 함*/
    }

} /*rule 17.04: int형 함수인데 return값이 없음*/