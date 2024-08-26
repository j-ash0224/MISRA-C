#define _CRT_SECURE_NO_WARNINGS 
#define STRINGIFY(text, text2) # text##text2 /*# rule 20.13*/ /*rule 20.10, rule 20.11*/ 
#define texta 실패
#define textb 하셨습니다.
#define textMerge STRINGIFY(texta, textb)
#define SUM(num1, num2) ((num1) + (num2))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> /*rule 21.10*/

#include <stdbool.h>

#include <stdarg.h> /*rule 17.01: stdarg.h는 include가 금지된 파일임*/
#include <setjmp.h> /*Rule 21.04*/
#include <signal.h> /*Rule 21.05*/
#include <tgmath.h> /*Rule 21.11*/
#include <fenv.h> /*Rule 21.12*/

char again = ' ';
int grade; /* rule 08.06 */
char error;

/************************************************** 사칙 연산 게임**************************************************/

/*난수 정의, 사칙연산 로직 정의, 정답유무와 점수계산 로직 정의 함수*/
void generateProblemAndCalculateScore(int* score, int levelscore, int operation) { /*rule 15.05: 함수가 2 개의 exit point 를 가짐 */
    int num1 = rand() % 99 + 1; /*1 ~ 99 숫자 랜덤*/
    int num2 = rand() % 99 + 1;
    int answer, userAnswer;

    switch (operation) {
    case 0: /*더하기 > 오버플로우 테스트 가능성 야기*/
        //answer = SUM(num1); /*Rule 01.03*/
        answer = num1 + num2;
        printf("%d + %d = ", num1, num2); /*rule 17.07: 반환값 미사용 또는 미저장됨*/
        break;
    case 1: /*빼기 > 언더플로우 테스트 가능성 야기*/
        answer = num1 - num2;
        printf("%d - %d = ", num1, num2);
        break;
    case 2: /*곱하기 > 오버플로우, 언더플로우 테스트 가능성 야기*/
        answer = num1 * num2;
        printf("%d * %d = ", num1, num2);
        feclearexcept(answer);  // 모든 예외 플래그를 초기화
        feraiseexcept(FE_OVERFLOW);  /*rule  FE_OVERFLOW 사용*/
        if (feclearexcept(answer)) {
            printf("오버플로우 발생 !");
        }
        break;
    default: {
        printf("디폴트문이 실행되었다 !\n"); /*rule 16.05: default 절이 첫번쨰 절 또는 마지막 절이 아님*/
    }
    case 3: /*나누기*/ /*rule 16.03: switch절이 break문으로 끝나지 않음*/
        answer = num1 / num2;
        printf("%d / %d = ", num1, num2);
        break;
        return;
    }


    scanf("%d", &userAnswer);

    /*정답유무와 점수계산*/
    if (userAnswer == answer) {
        printf("정답!\n");
        (*score) += levelscore;
    }
    else {
        while (getchar() != '\n'); /*rule 15.06: 반복문의 body가 복합문이 아님*/
        printf("땡, 정답은 %d.\n", answer);
    }
}

/*점수에 따른 등급 판단 함수*/
void calculateGradeAndPrint(int score, int level, char again) {
    int grade = 1000000;
    char gradeBuffer;
    char gradeBufferText[10] = "";
    gradeBuffer = gradeBufferText[100]; /*rule 18.01: 포인터의 연산 결과가 해당 포인터 gradeBufferText 가 가리키는 배열 gradeBufferText의 요소가 아님*/
    //gradeBuffer = *(gradeBufferText + 100);

    short errorgrade = (short)grade; /*rule 02.03*/


    /*복합조건*/
    if ((score >= 9 && level == 3) || (score == 6 && level == 2) || (score == 3 && level == 1)) {
        FILE* file1 = fopen("1st_grade.txt", "r");
        if (file1 == NULL) {
            printf("파일을 열지 못하였습니다.\n");
            return 1;
        }
        else {
            char ch;
            while ((ch = fgetc(file1)) != EOF) {
                putchar(ch);
            }
            fprintf(file1, "파일 읽기모드에서 쓰기 시도.\n"); /*rule 22.04: 서로다른 스트림에서 같은 파일을 동시에 읽기, 쓰기로 열었음*/
            char c = *(char*)file1; /*rule 22.05 FILE 객체를 가리키는 포인터 file1을 역참조함*/
            printf("FILE 객체의 첫 번째 바이트: %c\n", c);
            FILE* file2 = fopen("1st_grade.txt", "w"); /*rule 22.03: 서로다른 스트림에서 같은 파일을 동시에 읽기, 쓰기로 열었음*/
            FILE* file3 = fopen("1st_grade.txt", "r");
            fprintf(file2, "1등급입니다. 축하합니다.(파일내용)\n");

            fclose(file1);
            if (fgets(gradeBufferText, sizeof(gradeBufferText), file1) != NULL) { /*rule 22.06: file1이 닫히고 사용을 시도함*/
                //printf("버퍼를 출력한 내용: %s\n", gradeBuffer);
            }
            //fclose(file2);

            if (fgets(gradeBufferText, sizeof(gradeBufferText), file3) != NULL) {
                printf("버퍼를 출력한 내용: %s\n", gradeBufferText);
            }

            fclose(file3);

        }

        grade = 1;
    }
    else if ((score >= 6 && level == 3) || (score == 4 && level == 2) || (score == 2 && level == 1)) {
        grade = 2;
    }
    else if ((score >= 3 && level == 3) || (score == 2 && level == 2) || (score == 1 && level == 1)) {
        grade = 3;

    }
    else {
        grade = 0;
    }


    printf("당신의 점수는 %d점입니다. %d등급 입니다.\n", score, grade, errorgrade);
    printgrade(grade);
    /*게임이 끝나면 계속할지 여부를 again으로 초기화하고 사용자의 입력을 받아 결정*/

    printf("계속하시겠습니까???\ (y/n)\n>> ");
    scanf(" %c", &again);
    printf("\n");

    if (again == 'n' || again == 'N') {
        printf("메인메뉴로 이동합니다.\n");
        main();
    }
    else if (again == 'y' || again == 'Y') {
        runMathQuiz(0, 0);
    }
    else {
        printf("잘못된 입력입니다, 메인화면으로 이동합니다.\n");
        while (getchar() != '\n'); /*입력버퍼 비움*/
        main();
    }
} /*rule 22.01: 파일포인터 file2 가 명시적으로 해제되지 않았음*/



/*사칙연산게임 시작 함수*/
int runMathQuiz(int level, int score) { /*rule 17.02: 함수가 재귀호출 형태를 가지면 안됨*/
    level, score = 0; /*rule 18.07*/
    srand(time(NULL)); /*rule 22.10*/
    startGame(true);

    /*레벨입력*/
    printf("(1-3): ");
    scanf("%d", &level);

    /*레벨 예외상황 정의*/
    if (level < 1 || level > 3) {
        printf("레벨을 잘못 입력하였습니다.\n");
        while (getchar() != '\n'); /*입력버퍼 비움*/
        runMathQuiz(0, 0);
    }

    int levelscore = level;

    /*4칙연산 중 하나 랜덤선별 3번*/
    for (int i = 0; i < 3; i++) {
        int operation = rand() % 4;
        generateProblemAndCalculateScore(&score, levelscore, operation, error); /*rule 17.03: 인자의 개수와 파라미터의 개수가 일치하지 않음*/
    }

    calculateGradeAndPrint(score, level, again);

    return 0;
}