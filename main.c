char rule2001[20] = "rule 20.01을 위반하는 코드"; /*rule 20.01*/
#undef blabla /*rule20.05: undef가 사용되면 안됨*/

#define enum 3 /*rule 20.04: enum은 정의가 금지된 매크로임*/
#define calloc malloc /*rule 21.02: calloc은 정의가 금지된 매크로임*/

#define _CRT_SECURE_NO_WARNINGS /*rule 22.01*/
#define STRINGIFY(text, text2) # text##text2 /*# rule 20.13*/ /*rule 20.10: # 연산자가 사용됨, rule 20.11: 전처리 연산자 #의  피연산자 바로 뒤에 ##을 사용함 */ 
#define texta 실패
#define textb 하셨습니다.
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

// 8-10 : 인라인 함수가 static으로 선언되지 않음
inline void logOut() {
    int userGrade;
    printf("게임을 종료하기 전 게임 만족도를 남겨주시겠어요??- (1~5)"); // 4-1 : Trigraph 가 사용됨
    scanf("%d", &userGrade);
    float fa = 0.00;
    double grade = userGrade + fa; //10-6 : 타입이 float인 복합수식문이 더 큰 타입인 double로 변환되었음
}

int main() {
  
    short a122 = -32768;
    a122 >> 327682; // 12-2 : shift 연산자의 우측 피연산자가 좌측 피연산자의 범위를 벗어남
                    // 2-2 : >> 의 계산결과사 사용되지 않음 (죽은 코드)
                    // 10-1 : shift 및 bitwise 연산들은 타입이 unsigned인 객체에 대해서만 수행되어야 한다. 

    void* x = 8; // 11-6 int 타입과 void 포인트 타입 간 변환 발생
    int y = (int*)x - 6; // 11-5 : void 포인터 타입이 int 포인터 타입으로 형 변환
    int z = ((x = 1), (y = 2)); //12-3 : Comma 연산자 사용
    
    if (z > 1 && y++ > 0) { // 13-5 : 논리연산자 && 우측 항에 side effect
        if (x = y) { //13-4 : 할당 연산자를 조건식에 사용
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
    printf("=  **게임을 골라주세요.**   =\n=  1.가위바위보             =\n=  2.사칙연산               =\n=  3.야구게임               =\n=  4.업다운게임             =\n=  5.종료                   =\n");
    printf("=============================\n");

    int user_choice;

    while (1) {
        scanf("%d", &user_choice);
        if (user_choice < 1 || user_choice > 5) {
            printf("유효하지 않은 값 입니다. 다시 입력하세요\n");
        }
        else {
            break;
        }
    }

    if (user_choice == (c * (a * b))) { // 11-7 : 타입이 unsigned short인 복합수식문이 더 큰 타입인 unsigned int로 변환
        rock_Scissors_Paper(); 
    }

    else if (user_choice == ((int)(a + b))) { // 10-8 : 타입이 unsigned short인 복합수식문을 int로 변환
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
        int* intPtr = (int*)funcPtr; 	// 11-1 : 함수 포인터가 int 타입으로 변환
        
        exit(0);  /*rule 21.08: exit은 사용이 금지된 함수임*/
    }

    return 0; /*rule 15.07*/
}