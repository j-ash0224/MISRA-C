#define _CRT_SECURE_NO_WARNINGS 
#define STRINGIFY(text, text2) # text##text2 /*# rule 20.13*/ /*rule 20.10, rule 20.11*/ 
#define texta ����
#define textb �ϼ̽��ϴ�.
#define textMerge STRINGIFY(texta, textb)
#define SUM(num1, num2) ((num1) + (num2))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> /*rule 21.10*/

#include <stdbool.h>

#include <stdarg.h> /*rule 17.01: stdarg.h�� include�� ������ ������*/
#include <setjmp.h> /*Rule 21.04*/
#include <signal.h> /*Rule 21.05*/
#include <tgmath.h> /*Rule 21.11*/
#include <fenv.h> /*Rule 21.12*/

char again = ' ';
int grade; /* rule 08.06 */
char error;

/************************************************** ��Ģ ���� ����**************************************************/

/*���� ����, ��Ģ���� ���� ����, ���������� ������� ���� ���� �Լ�*/
void generateProblemAndCalculateScore(int* score, int levelscore, int operation) { /*rule 15.05: �Լ��� 2 ���� exit point �� ���� */
    int num1 = rand() % 99 + 1; /*1 ~ 99 ���� ����*/
    int num2 = rand() % 99 + 1;
    int answer, userAnswer;

    switch (operation) {
    case 0: /*���ϱ� > �����÷ο� �׽�Ʈ ���ɼ� �߱�*/
        //answer = SUM(num1); /*Rule 01.03*/
        answer = num1 + num2;
        printf("%d + %d = ", num1, num2); /*rule 17.07: ��ȯ�� �̻�� �Ǵ� �������*/
        break;
    case 1: /*���� > ����÷ο� �׽�Ʈ ���ɼ� �߱�*/
        answer = num1 - num2;
        printf("%d - %d = ", num1, num2);
        break;
    case 2: /*���ϱ� > �����÷ο�, ����÷ο� �׽�Ʈ ���ɼ� �߱�*/
        answer = num1 * num2;
        printf("%d * %d = ", num1, num2);
        feclearexcept(answer);  // ��� ���� �÷��׸� �ʱ�ȭ
        feraiseexcept(FE_OVERFLOW);  /*rule  FE_OVERFLOW ���*/
        if (feclearexcept(answer)) {
            printf("�����÷ο� �߻� !");
        }
        break;
    default: {
        printf("����Ʈ���� ����Ǿ��� !\n"); /*rule 16.05: default ���� ù���� �� �Ǵ� ������ ���� �ƴ�*/
    }
    case 3: /*������*/ /*rule 16.03: switch���� break������ ������ ����*/
        answer = num1 / num2;
        printf("%d / %d = ", num1, num2);
        break;
        return;
    }


    scanf("%d", &userAnswer);

    /*���������� �������*/
    if (userAnswer == answer) {
        printf("����!\n");
        (*score) += levelscore;
    }
    else {
        while (getchar() != '\n'); /*rule 15.06: �ݺ����� body�� ���չ��� �ƴ�*/
        printf("��, ������ %d.\n", answer);
    }
}

/*������ ���� ��� �Ǵ� �Լ�*/
void calculateGradeAndPrint(int score, int level, char again) {
    int grade = 1000000;
    char gradeBuffer;
    char gradeBufferText[10] = "";
    gradeBuffer = gradeBufferText[100]; /*rule 18.01: �������� ���� ����� �ش� ������ gradeBufferText �� ����Ű�� �迭 gradeBufferText�� ��Ұ� �ƴ�*/
    //gradeBuffer = *(gradeBufferText + 100);

    short errorgrade = (short)grade; /*rule 02.03*/


    /*��������*/
    if ((score >= 9 && level == 3) || (score == 6 && level == 2) || (score == 3 && level == 1)) {
        FILE* file1 = fopen("1st_grade.txt", "r");
        if (file1 == NULL) {
            printf("������ ���� ���Ͽ����ϴ�.\n");
            return 1;
        }
        else {
            char ch;
            while ((ch = fgetc(file1)) != EOF) {
                putchar(ch);
            }
            fprintf(file1, "���� �б��忡�� ���� �õ�.\n"); /*rule 22.04: ���δٸ� ��Ʈ������ ���� ������ ���ÿ� �б�, ����� ������*/
            char c = *(char*)file1; /*rule 22.05 FILE ��ü�� ����Ű�� ������ file1�� ��������*/
            printf("FILE ��ü�� ù ��° ����Ʈ: %c\n", c);
            FILE* file2 = fopen("1st_grade.txt", "w"); /*rule 22.03: ���δٸ� ��Ʈ������ ���� ������ ���ÿ� �б�, ����� ������*/
            FILE* file3 = fopen("1st_grade.txt", "r");
            fprintf(file2, "1����Դϴ�. �����մϴ�.(���ϳ���)\n");

            fclose(file1);
            if (fgets(gradeBufferText, sizeof(gradeBufferText), file1) != NULL) { /*rule 22.06: file1�� ������ ����� �õ���*/
                //printf("���۸� ����� ����: %s\n", gradeBuffer);
            }
            //fclose(file2);

            if (fgets(gradeBufferText, sizeof(gradeBufferText), file3) != NULL) {
                printf("���۸� ����� ����: %s\n", gradeBufferText);
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


    printf("����� ������ %d���Դϴ�. %d��� �Դϴ�.\n", score, grade, errorgrade);
    printgrade(grade);
    /*������ ������ ������� ���θ� again���� �ʱ�ȭ�ϰ� ������� �Է��� �޾� ����*/

    printf("����Ͻðڽ��ϱ�???\ (y/n)\n>> ");
    scanf(" %c", &again);
    printf("\n");

    if (again == 'n' || again == 'N') {
        printf("���θ޴��� �̵��մϴ�.\n");
        main();
    }
    else if (again == 'y' || again == 'Y') {
        runMathQuiz(0, 0);
    }
    else {
        printf("�߸��� �Է��Դϴ�, ����ȭ������ �̵��մϴ�.\n");
        while (getchar() != '\n'); /*�Է¹��� ���*/
        main();
    }
} /*rule 22.01: ���������� file2 �� ��������� �������� �ʾ���*/



/*��Ģ������� ���� �Լ�*/
int runMathQuiz(int level, int score) { /*rule 17.02: �Լ��� ���ȣ�� ���¸� ������ �ȵ�*/
    level, score = 0; /*rule 18.07*/
    srand(time(NULL)); /*rule 22.10*/
    startGame(true);

    /*�����Է�*/
    printf("(1-3): ");
    scanf("%d", &level);

    /*���� ���ܻ�Ȳ ����*/
    if (level < 1 || level > 3) {
        printf("������ �߸� �Է��Ͽ����ϴ�.\n");
        while (getchar() != '\n'); /*�Է¹��� ���*/
        runMathQuiz(0, 0);
    }

    int levelscore = level;

    /*4Ģ���� �� �ϳ� �������� 3��*/
    for (int i = 0; i < 3; i++) {
        int operation = rand() % 4;
        generateProblemAndCalculateScore(&score, levelscore, operation, error); /*rule 17.03: ������ ������ �Ķ������ ������ ��ġ���� ����*/
    }

    calculateGradeAndPrint(score, level, again);

    return 0;
}