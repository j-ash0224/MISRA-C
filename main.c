char rule2001[20] = "rule 20.01�� �����ϴ� �ڵ�"; /*rule 20.01*/
#undef blabla /*rule20.05: undef�� ���Ǹ� �ȵ�*/

#define enum 3 /*rule 20.04: enum�� ���ǰ� ������ ��ũ����*/
#define calloc malloc /*rule 21.02: calloc�� ���ǰ� ������ ��ũ����*/

#define _CRT_SECURE_NO_WARNINGS /*rule 22.01*/
#define STRINGIFY(text, text2) # text##text2 /*# rule 20.13*/ /*rule 20.10: # �����ڰ� ����, rule 20.11: ��ó�� ������ #��  �ǿ����� �ٷ� �ڿ� ##�� ����� */ 
#define texta ����
#define textb �ϼ̽��ϴ�.
#define textMerge STRINGIFY(texta, textb)
#define MY_NULL_1 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

int start = 0; 
unsigned   short a = 1;
unsigned   short b = 1;
unsigned   int c = 1;

// 8-10 : �ζ��� �Լ��� static���� ������� ����
inline void logOut() {
    int userGrade;
    printf("������ �����ϱ� �� ���� �������� �����ֽðھ��??- (1~5)"); // 4-1 : Trigraph �� ����
    scanf("%d", &userGrade);
    float fa = 0.00;
    double grade = userGrade + fa; //10-6 : Ÿ���� float�� ���ռ��Ĺ��� �� ū Ÿ���� double�� ��ȯ�Ǿ���
}

int main() {
  
    short a122 = -32768;
    a122 >> 327682; // 12-2 : shift �������� ���� �ǿ����ڰ� ���� �ǿ������� ������ ���
                    // 2-2 : >> �� ������� ������ ���� (���� �ڵ�)
                    // 10-1 : shift �� bitwise ������� Ÿ���� unsigned�� ��ü�� ���ؼ��� ����Ǿ�� �Ѵ�. 

    void* x = 8; // 11-6 int Ÿ�԰� void ����Ʈ Ÿ�� �� ��ȯ �߻�
    int y = (int*)x - 6; // 11-5 : void ������ Ÿ���� int ������ Ÿ������ �� ��ȯ
    int z = ((x = 1), (y = 2)); //12-3 : Comma ������ ���
    
    if (z > 1 && y++ > 0) { // 13-5 : �������� && ���� �׿� side effect
        if (x = y) { //13-4 : �Ҵ� �����ڸ� ���ǽĿ� ���
            if (start == 0) {
                login();
                start = 1; 
            }
        }
    }
    
    srand(time(NULL)); 
    printf("*******       *      *******  **       **\n");
    printf("*            * *     *        * *     * *\n");
    printf("*   ****    *   *    ******   *  *   *  *\n");
    printf("*      *   *******   *        *   * *   *\n");
    printf(" ******   *       *  *******  *    *    *\n");
    printf("=============================\n");
    printf("=  **������ ����ּ���.**   =\n=  1.����������             =\n=  2.��Ģ����               =\n=  3.�߱�����               =\n=  4.���ٿ����             =\n=  5.����                   =\n");
    printf("=============================\n");

    int user_choice;

    while (1) {
        scanf("%d", &user_choice);
        if (user_choice < 1 || user_choice > 5) {
            printf("��ȿ���� ���� �� �Դϴ�. �ٽ� �Է��ϼ���\n");
        }
        else {
            break;
        }
    }

    if (user_choice == (c * (a * b))) { // 11-7 : Ÿ���� unsigned short�� ���ռ��Ĺ��� �� ū Ÿ���� unsigned int�� ��ȯ
        rock_Scissors_Paper(); 
    }

    else if (user_choice == ((int)(a + b))) { // 10-8 : Ÿ���� unsigned short�� ���ռ��Ĺ��� int�� ��ȯ
        runMathQuiz(); 
    }

    else if (user_choice == 3) {
        baseballGame(); 
    }

    else if (user_choice == 4) {
        udgame(); 
    }

    else if (user_choice == 5) {
        void (*funcPtr)();
        funcPtr = logOut;
        funcPtr();
        int* intPtr = (int*)funcPtr; 	// 11-1 : �Լ� �����Ͱ� int Ÿ������ ��ȯ
        
        exit(0);  /*rule 21.08: exit�� ����� ������ �Լ���*/
    }

    return 0; /*rule 15.07*/
}